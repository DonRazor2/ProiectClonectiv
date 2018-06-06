#include "drum.h"
#include <QDebug>

Drum::Drum()
    :mSemafor(true)
{
    qInfo() << "Drum creat!";
}

void Drum::info()
{
    QString color = mSemafor ? "Verde" : "Rosu";
    qInfo() << "Info despre drum : " << mMasini.size() << " " << color;
}

void Drum::addMasina(Masina *masinaAdaugata)
{
    mMasini.push_back(masinaAdaugata);
}

Masina* Drum::removeMasina()
{
    Masina* retVal(nullptr);
    if(!mMasini.isEmpty() && mSemafor)
    {
        retVal = mMasini.front();
        mMasini.pop_front();
    }
    return retVal;
}

bool Drum::changeSemafor()
{
    mSemafor = !mSemafor;
    QString color = mSemafor ? "Verde" : "Rosu";
    qInfo() << "Culoare Semafor : " << color;
    return mSemafor;
}

bool Drum::getSemafor()
{
    QString color = mSemafor ? "Verde" : "Rosu";
    qInfo() << "Culoare Semafor : " << color;
    return mSemafor;
}
