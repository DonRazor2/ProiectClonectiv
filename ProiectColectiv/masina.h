#ifndef MASINA_H
#define MASINA_H

#include <QObject>

class Masina : public QObject
{
    Q_OBJECT

    enum Orientare
    {
        INAINTE = 0,
        //STANGA,
        //DREAPTA
    };

public:
    explicit Masina(QObject *parent = nullptr);
signals:

public slots:

private:
    Orientare mOrientare;
    QString mPozaUrl;
};

#endif // MASINA_H
