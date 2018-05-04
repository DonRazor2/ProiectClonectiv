#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "drum.h"
#include "intersectie.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Drum drume [8];
    Intersectie intersectie;
    for(int i = 0; i < 8; i++)
    {
        intersectie.connectareDrum(i, &drume[i]);
    }
    drume[7].addMasina(nullptr);
    intersectie.info();

    drume[0].addMasina(nullptr);
    drume[2].addMasina(nullptr);
    intersectie.intrareMasina(2 ,Masina::INAINTE);

    intersectie.info();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
