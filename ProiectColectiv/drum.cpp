#include "drum.h"
#include <QDebug>

Drum::Drum(QObject *parent) : QObject(parent)
{
    mSemaforVerde = true;
    qInfo() << "Drum creat!";
}

void Drum::infoDrum()
{
    qInfo() << "Info despre drum";
}
