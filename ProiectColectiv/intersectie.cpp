#include "intersectie.h"
#include <QDebug>

Intersectie::Intersectie()
{
    qInfo() << "Intersectie creata";
}

void Intersectie::connectareDrum(int punctConectare, Drum *drumConectat)
{
    mPuncteDeConectare[punctConectare] = new PunctConectare(drumConectat);
    qInfo() << "Drum Conectat!";
}

void Intersectie::intrareMasina(int punctConectare, Masina::Orientare intentieDeMers)
{
    if (!mPuncteDeConectare[punctConectare] -> mCuloareSemafor)
    {
        switch (intentieDeMers) {
        case Masina::INAINTE:
            mPuncteDeConectare[0] -> mDrumConectat -> addMasina(mPuncteDeConectare[punctConectare] -> mDrumConectat -> removeMasina());
            break;
        default:
            break;
        }
    }
}

void Intersectie::info()
{
    qInfo() << "Info Intersectie : \n";
    for (int i = 0 ; i < 8 ; i++)
    {
        qInfo() << mPuncteDeConectare[i] -> mCuloareSemafor << " " ;
        mPuncteDeConectare[i] -> mDrumConectat -> info();
    }
}
