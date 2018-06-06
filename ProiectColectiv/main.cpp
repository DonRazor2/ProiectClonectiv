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

    intersectie.legareDrum("1 -> 5", "1", "5", Masina::INAINTE);   // din drumul 1 iese masina si intra in drumul 5
    intersectie.legareDrum("2 -> 6", "2", "6", Masina::INAINTE);   // din drumul 2 iese masina si intra in drumul 6
    intersectie.legareDrum("7 -> 3", "7", "3", Masina::INAINTE);
    intersectie.legareDrum("8 -> 4", "8", "4", Masina::INAINTE);
    intersectie.legareDrum("16 -> 12", "16", "12", Masina::INAINTE);
    intersectie.legareDrum("15 -> 11", "15", "11", Masina::INAINTE);
    intersectie.legareDrum("10 -> 14", "10", "14", Masina::INAINTE);
    intersectie.legareDrum("9 -> 13", "9", "13", Masina::INAINTE);

    //Iesiri de pe drum.
    intersectie.legareDrum("5 -> ?", "5", "?", Masina::INAINTE);
    intersectie.legareDrum("6 -> ?", "6", "?", Masina::INAINTE);
    intersectie.legareDrum("3 -> ?", "3", "?", Masina::INAINTE);
    intersectie.legareDrum("4 -> ?", "4", "?", Masina::INAINTE);
    intersectie.legareDrum("12 -> ?", "12", "?", Masina::INAINTE);
    intersectie.legareDrum("11 -> ?", "11", "?", Masina::INAINTE);
    intersectie.legareDrum("13 -> ?", "13", "?", Masina::INAINTE);
    intersectie.legareDrum("14 -> ?", "14", "?", Masina::INAINTE);


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
