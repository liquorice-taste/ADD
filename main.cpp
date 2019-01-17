#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "httprequest.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    httpRequest h;
    QQmlContext *context = engine.rootContext();
        /* Load the object in context to establish a connection,
         * also define the name by which the connection will be
         * */
    context->setContextProperty("hi", &h);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
