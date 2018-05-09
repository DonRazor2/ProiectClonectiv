#ifndef DRUM_H
#define DRUM_H

#include <QObject>
#include <QQueue>
#include "masina.h"

class Drum : public QObject
{
    Q_OBJECT
public:
    Drum();
    void info();
    void addMasina(Masina *masinaAdaugata);
    Masina* removeMasina();

private:
    QQueue <Masina*> mMasini; // TO DO : COADA MASINI
};

#endif // DRUM_H
