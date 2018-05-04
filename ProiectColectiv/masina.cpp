#include "masina.h"
#include <QDebug>

Masina::Masina()
{
    mOrientare = Orientare::INAINTE;
    mPozaUrl = "";
    qInfo() << "Masina Creata, Masini create pana in punctul asta : ";
}

Masina::Masina(Orientare orientare, QString pozaUrl)
    : mOrientare(orientare),
      mPozaUrl(pozaUrl)
{

}
