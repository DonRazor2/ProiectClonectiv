#ifndef INTERSECTIE_H
#define INTERSECTIE_H

#include <QObject>
#include "Drum.h"

class Intersectie : public QObject
{
    Q_OBJECT
public:
    explicit Intersectie(QObject *parent = nullptr);
    void connectareDrum(int punctConectare, Drum* drumConectat);

signals:

public slots:

public:
    Drum* mPuncteDeConectare [8];
};

#endif // INTERSECTIE_H
