#ifndef INTERSECTIE_H
#define INTERSECTIE_H

#include <QObject>
#include "drum.h"
#include "masina.h"

class Intersectie : public QObject
{
    Q_OBJECT
    struct PunctConectare
    {
        PunctConectare(Drum* drum)
        {
            mDrumConectat = drum;
        }

        bool mCuloareSemafor = false;
        Drum* mDrumConectat;
    };

public:
    explicit Intersectie();
    void connectareDrum(int punctConectare, Drum* drumConectat);
    void intrareMasina(int punctConectare, Masina::Orientare intentieDeMers);
    void info();

signals:

public slots:

public:
    PunctConectare* mPuncteDeConectare [8];
};

#endif // INTERSECTIE_H
