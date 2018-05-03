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
    for(int i = 0; i < 8;)
    {
        intersectie.connectareDrum(i, &drume[i]);
        i++;
        intersectie.mPuncteDeConectare[i]->infoDrum();
    }

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
