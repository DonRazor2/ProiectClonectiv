#include "masina.h"
#include <QDebug>

Masina::Masina()
{
    mOrientare = Orientare::INAINTE;
    mPozaUrl = "";
}

Masina::Masina(Orientare orientare, QString pozaUrl)
    : mOrientare(orientare),
      mPozaUrl(pozaUrl)
{

}
