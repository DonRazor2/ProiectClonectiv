#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include <QPair>
#include "drum.h"
#include "intersectie.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //test purposes
    Masina masinuta; // folosim aceasi masina sa simplificam treaba..
    Drum someDrum;

    QList<QPair<QString, Drum*>> HartaDrumuri;
    HartaDrumuri.append(qMakePair(QString("1"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("2"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("3"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("4"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("5"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("6"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("7"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("8"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("9"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("10"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("11"), new Drum()));
    HartaDrumuri.append(qMakePair(QString("12"), new Drum()));

    Intersectie intersectie;
    for(QPair<QString, Drum*> pair : HartaDrumuri)
    {
        intersectie.connectareDrum(pair.first, pair.second, {Masina::INAINTE});
    }

    intersectie.legareDrum("Legatura1", "5", "1", Masina::INAINTE);   // din drumul 1 iese masina si intra in drumul 5
    intersectie.legareDrum("Legatura2", "6", "2", Masina::INAINTE);   // din drumul 2 iese masina si intra in drumul 6
    intersectie.legareDrum("Legatura3", "...", "5", Masina::INAINTE); // din drumul 5 iese masina si iese din peisaj

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
