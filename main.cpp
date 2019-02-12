#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QDebug>
#include <QQmlContext>
#include "httprequest.h"
#include "dicmodel.h"
#include "requestmodel.h"

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    httpRequest HttpRequest;
    //HttpRequest.getData("hell");

    qmlRegisterType<DicModel>("Model", 1, 0, "DicModel");
    qmlRegisterType<HeadwordEntryList>();//"Model", 1, 0, "HeadwordEntryList");
    HeadwordEntryList headEntry;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("headEntry"), &headEntry);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
