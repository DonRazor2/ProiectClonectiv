#include "sincronizator.h"

Sincronizator::Sincronizator(Intersectie *intersectie)
{
    this->intersectie = intersectie;
}

void Sincronizator::legareSemafoare(QString numeLegaturaSemafoare, QList<Drum*> drumuri)
{
    QList<Drum*> listaAdaugata;
    for(Drum* drum : drumuri)
    {
        listaAdaugata.append(drum);
    }
    listaLegaturi.append(qMakePair(numeLegaturaSemafoare, listaAdaugata));
}

void Sincronizator::sincronizare(QString numeLegaturaSemafoare)
{
    for(QPair<QString, QList<Drum*>> legatura : listaLegaturi)
    {
        if(legatura.first == numeLegaturaSemafoare)
        {
            for(Drum* drum: legatura.second)
            {
                drum->changeSemafor();
            }
        }
    }
}


