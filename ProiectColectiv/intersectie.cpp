#include "intersectie.h"
#include <QDebug>
#include <QPair>

Intersectie::Intersectie()
{
    qInfo() << "Intersectie creata";
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
            return pair.second->mDrumConectat->removeMasina();
        }
    }
    return nullptr;
}

void Intersectie::mutareMasina(QString drumIesire, QString drumIntrare)
{
    // to do : check for valid connection betwen roads
    intrareMasina(drumIntrare, iesireMasina(drumIesire));
}

void Intersectie::legareDrum(QString drumIntrare, QString drumIesire, Masina::Orientare orientare)
{
    LegaturaDrumuri nouaLegatura {drumIntrare, drumIesire, orientare};
    mLegaturiDrumuri.append(nouaLegatura);
}

void Intersectie::info()
{
    qInfo() << "Info Intersectie :";
    for(QPair<QString, PunctConectare*> pair : mPuncteDeConectare)
    {
        qInfo() << pair.first << " " << pair.second->mCuloareSemafor;
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
