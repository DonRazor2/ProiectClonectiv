#ifndef INTERSECTIE_H
#define INTERSECTIE_H

#include <QObject>
#include <QMap>
#include <QPair>
#include <QTimer>
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

        Drum* mDrumConectat;
        QList<Masina::Orientare> mOrientareDrum;
    };

    struct LegaturaDrumuri
    {
        QString numeLegatura;
        QString drumIesire;
        QString drumIntrare;
        Masina::Orientare orientare;
    };

public:
    explicit Intersectie();
    void connectareDrum(QString numeDrum, Drum* drumConectat, QList<Masina::Orientare> orientare);
    void intrareMasina(QString numeDrum, Masina* masinaAdaugata);
    Masina* iesireMasina(QString numeDrum);
    void mutareMasina(QString numeLegatura);
    void legareDrum(QString numeLegatura, QString drumIntrare, QString drumIesire, Masina::Orientare orientare);
    void schimbareSemafor(QString numeDrum);
    void info();
    void infoLegaturi();
    void start();

public slots:
    void tick();

private:
    QList<QPair<QString, PunctConectare*>> mPuncteDeConectare;
    QList<LegaturaDrumuri> mLegaturiDrumuri;


    QTimer *timer;
};

#endif // INTERSECTIE_H
