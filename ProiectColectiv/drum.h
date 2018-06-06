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
    bool changeSemafor();
    bool getSemafor();

private:
    QQueue <Masina*> mMasini;
    bool mSemafor;
};

#endif // DRUM_H
