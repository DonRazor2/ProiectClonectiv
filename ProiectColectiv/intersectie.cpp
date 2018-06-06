#include "intersectie.h"
#include <QDebug>
#include <QPair>
#include <QTime>
#include <QRandomGenerator>

Intersectie::Intersectie()
{
    qInfo() << "Intersectie creata";
    timer = new QTimer(this);
    timer->setInterval(3000);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

    QTime time = QTime::currentTime();
    qsrand((quint16)time.msec());
}

void Intersectie::connectareDrum(QString numeDrum, Drum* drumConectat, QList<Masina::Orientare> orientare)
{
    QPair<QString, PunctConectare*> newPair = qMakePair(numeDrum, new PunctConectare(drumConectat, orientare));
    mPuncteDeConectare.append(newPair);
    qInfo() << "Drum Conectat!";
}

void Intersectie::intrareMasina(QString numeDrum, Masina* masinaAdaugata)
{
    for(QPair<QString, PunctConectare*> pair : mPuncteDeConectare)
    {
        if(pair.first == numeDrum)
        {
            if(masinaAdaugata != nullptr)
            {
                pair.second->mDrumConectat->addMasina(masinaAdaugata);
                return;
            }
        }
    }
}

Masina *Intersectie::iesireMasina(QString numeDrum)
{
    for(QPair<QString, PunctConectare*> pair : mPuncteDeConectare)
    {
        if(pair.first == numeDrum)
        {
            if(pair.second->mDrumConectat->getSemafor())
            {
                return pair.second->mDrumConectat->removeMasina();
            }
        }
    }
    return nullptr;
}

void Intersectie::mutareMasina(QString numeLegatura)
{
    for(LegaturaDrumuri legatura : mLegaturiDrumuri)
    {
        if (legatura.numeLegatura == numeLegatura)
        {
            Masina* masinaIesita = iesireMasina(legatura.drumIesire);
            if(masinaIesita != nullptr)
            {
                intrareMasina(legatura.drumIntrare, masinaIesita);
            }
        }
    }
}

void Intersectie::legareDrum(QString numeLegatura, QString drumIesire, QString drumIntrare, Masina::Orientare orientare)
{
    //to do : check if it dies.
    LegaturaDrumuri nouaLegatura {numeLegatura ,drumIesire, drumIntrare, orientare};
    mLegaturiDrumuri.append(nouaLegatura);
}

void Intersectie::schimbareSemafor(QString numeDrum)
{
    for(QPair<QString, PunctConectare*> pair : mPuncteDeConectare)
    {
        if(pair.first == numeDrum)
        {
            pair.second->mDrumConectat->changeSemafor();
        }
    }
}

void Intersectie::info()
{
    qInfo() << "Info Intersectie :";
    for(QPair<QString, PunctConectare*> pair : mPuncteDeConectare)
    {
        qInfo() << pair.first;
        pair.second->mDrumConectat->info();
    }

    qInfo() << " Legaturi : ";
    for(LegaturaDrumuri legatura : mLegaturiDrumuri)
    {
        //to do
        qInfo() << legatura.drumIntrare << " - " << legatura.drumIesire << " cu orientare INAINTE ";
    }
    qInfo() << " ----- ";
}

void Intersectie::start()
{
    timer->start();
}

void Intersectie::tick()
{
    static quint16 v = qrand() % 300;
    for(QPair<QString, PunctConectare*> pair : mPuncteDeConectare)
    {
        if(v % 5 == 0)
        {
            Masina* newCar = new Masina();
            pair.second->mDrumConectat->addMasina(newCar);
            qInfo() << v;
            qInfo() << "Masina adaugata la drumul : " << pair.first;
        }
        v = qrand() % 300;
    }

    for(LegaturaDrumuri legatura : mLegaturiDrumuri)
    {
        Masina* masinaIesita = iesireMasina(legatura.drumIesire);
        if(masinaIesita != nullptr)
        {
            intrareMasina(legatura.drumIntrare, masinaIesita);
        }
    }

    info();

    timer->start();
}
