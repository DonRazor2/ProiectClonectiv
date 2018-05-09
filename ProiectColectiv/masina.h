#ifndef MASINA_H
#define MASINA_H

#include <QObject>

class Masina : public QObject
{
    Q_OBJECT

public:
    typedef enum
    {
        INAINTE = 0,
        //STANGA,
        //DREAPTA
    }Orientare;

public:
    explicit Masina();
    Masina(Orientare orientare, QString pozaUrl);

private:
    Orientare mOrientare;
    QString mPozaUrl;
};

#endif // MASINA_H
