#ifndef SINCRONIZATOR_H
#define SINCRONIZATOR_H

#include <QObject>
#include <intersectie.h>

class Sincronizator : public QObject
{
    Q_OBJECT
public:
    explicit Sincronizator(Intersectie *intersectie);
    void legareSemafoare(QString numeLegaturaSemafoare, QList<Drum*> drumuri);
    void sincronizare(QString numeLegaturaSemafoare);

signals:

public slots:

private:
    Intersectie *intersectie;
    QList<QPair<QString,QList<Drum*>>> listaLegaturi;
};

#endif // SINCRONIZATOR_H
