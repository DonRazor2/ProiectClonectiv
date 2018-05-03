#ifndef DRUM_H
#define DRUM_H

#include <QObject>
#include "masina.h"

class Drum : public QObject
{
    Q_OBJECT
public:
    explicit Drum(QObject *parent = nullptr);
    void infoDrum();
signals:

public slots:

private:
    Masina mMasini[3]; // TO DO : COADA MASINI
    bool mSemaforVerde;
};

#endif // DRUM_H
