#ifndef SINCRONIZATOR_H
#define SINCRONIZATOR_H

#include <QObject>

class Sincronizator : public QObject
{
    Q_OBJECT
public:
    explicit Sincronizator(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SINCRONIZATOR_H