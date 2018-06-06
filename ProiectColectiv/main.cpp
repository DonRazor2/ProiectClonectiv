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

    intersectie.legareDrum("Legatura1", "Drum Principal Dreapta", "Drum Secundar", Masina::INAINTE);
    intersectie.legareDrum("Legatura2", "Drum Principal Dreapta", "Drum Principal Stanga", Masina::INAINTE);
    intersectie.legareDrum("Legatura3", "...", "Drum Principal Dreapta", Masina::INAINTE);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
