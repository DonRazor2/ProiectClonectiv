#ifndef INTERSECTIE_H
#define INTERSECTIE_H

#include <QObject>
#include <QMap>
#include <QPair>
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

    QMap<QString, PunctConectare*> ConectariIntersectie;

public:
    explicit Intersectie();
    void connectareDrum(QString numeDrum, Drum* drumConectat);
    void intrareMasina(QString numeDrum, Masina* masinaAdaugata);
    Masina* iesireMasina(QString numeDrum);
    void mutareMasina(Masina* masinaMutata);
    void info();

signals:

public slots:

public:
    QList<QPair<QString, PunctConectare*>> mPuncteDeConectare;
};

#endif // INTERSECTIE_H
