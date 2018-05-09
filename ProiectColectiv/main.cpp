#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include "drum.h"
#include "intersectie.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //test purposes
    Drum drumuri [3];
    Masina masinuta;
    for (int i = 0; i < 3; i++)
    {
        drumuri[i].addMasina(&masinuta);
    }

    Intersectie intersectie;
    intersectie.connectareDrum("Drum Principal Stanga", &drumuri[0]);
    intersectie.connectareDrum("Drum Principal Dreapta", &drumuri[1]);
    intersectie.connectareDrum("Drum Secundar", &drumuri[2]);

    intersectie.info();

    intersectie.mutareMasina("Drum Principal Stanga", "Drum Principal Dreapta");

    intersectie.info();

    intersectie.mutareMasina("Drum Principal Stanga", "Drum Principal Dreapta");

    intersectie.info();

    intersectie.intrareMasina("Drum Principal Stanga", &masinuta);
    intersectie.intrareMasina("Drum Principal Stanga", &masinuta);

    intersectie.info();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
