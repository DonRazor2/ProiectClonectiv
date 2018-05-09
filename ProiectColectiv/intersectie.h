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
        QList<Masina::Orientare> mOrientareDrum;
    };

    //to do
    QMap<QString, PunctConectare*> ConectariIntersectie
    {
        {"SudVest-1stLane", nullptr},
        {"SudVest-2ndLane", nullptr},
        {"NordVest-1stLane", nullptr},
        {"NordVest-2ndLane", nullptr},
        // to do finish
    };

public:
    explicit Intersectie();
    void connectareDrum(QString numeDrum, Drum* drumConectat);
    void intrareMasina(QString numeDrum, Masina* masinaAdaugata);
    Masina* iesireMasina(QString numeDrum);
    void mutareMasina(QString drumIesire, QString drumIntrare);
    void info();

private:
    QList<QPair<QString, PunctConectare*>> mPuncteDeConectare;
};

#endif // INTERSECTIE_H
