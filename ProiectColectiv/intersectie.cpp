#include "intersectie.h"
#include <QDebug>
#include <QPair>

Intersectie::Intersectie()
{
    qInfo() << "Intersectie creata";
}

void Intersectie::connectareDrum(QString numeDrum, Drum* drumConectat)
{
    QPair<QString, PunctConectare*> newPair = qMakePair(numeDrum, new PunctConectare(drumConectat));
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
    intrareMasina(drumIntrare, iesireMasina(drumIesire));
}

void Intersectie::info()
{
    qInfo() << "Info Intersectie : \n";
    for(QPair<QString, PunctConectare*> pair : mPuncteDeConectare)
    {
        qInfo() << pair.first << " " << pair.second->mCuloareSemafor;
        pair.second->mDrumConectat->info();
    }
}
