#include "intersectie.h"
#include <QDebug>

Intersectie::Intersectie(QObject *parent) : QObject(parent)
{
    qInfo() << "Intersectie creata";
}

void Intersectie::connectareDrum(int punctConectare, Drum *drumConectat)
{
    mPuncteDeConectare[punctConectare] = drumConectat;
    qInfo() << "Drum Conectat!";
}
