#include "masina.h"
#include <QDebug>

Masina::Masina(QObject *parent) : QObject(parent)
{
    mOrientare = Orientare::INAINTE;
    mPozaUrl = "";
    qInfo() << "Masina Creata, Masini create pana in punctul asta : ";
}
