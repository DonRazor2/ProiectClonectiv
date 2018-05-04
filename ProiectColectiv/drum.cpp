#include "drum.h"
#include <QDebug>

Drum::Drum()
{
    qInfo() << "Drum creat!";
}

void Drum::info()
{
    qInfo() << "Info despre drum : " << mMasini.size();
}

void Drum::addMasina(Masina *masinaAdaugata)
{
    mMasini.push_back(masinaAdaugata);
}

Masina* Drum::removeMasina()
{
    Masina* retVal;
    if(!mMasini.isEmpty())
    {
        retVal = mMasini.front();
        mMasini.pop_front();
    }
    return retVal;
}
