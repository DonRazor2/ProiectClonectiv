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
        PunctConectare(Drum* drum, QList<Masina::Orientare> orientare)
        {
            mDrumConectat = drum;
            mOrientareDrum.append(orientare);
        }

        bool mCuloareSemafor = false;
        Drum* mDrumConectat;
        QList<Masina::Orientare> mOrientareDrum;
    };
    struct LegaturaDrumuri
    {
        QString drumIntrare;
        QString drumIesire;
        Masina::Orientare orientare;
    };

public:
    explicit Intersectie();
    void connectareDrum(QString numeDrum, Drum* drumConectat, QList<Masina::Orientare> orientare);
    void intrareMasina(QString numeDrum, Masina* masinaAdaugata);
    Masina* iesireMasina(QString numeDrum);
    void mutareMasina(QString drumIesire, QString drumIntrare);
    void legareDrum(QString drumIntrare, QString drumIesire, Masina::Orientare orientare);
    void info();

private:
    QList<QPair<QString, PunctConectare*>> mPuncteDeConectare;
    QList<LegaturaDrumuri> mLegaturiDrumuri;
};

#endif // INTERSECTIE_H
