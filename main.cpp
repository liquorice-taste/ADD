#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "httprequest.h"
#include "dictionarymodel.h"
#include "requestmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    httpRequest HttpRequest;
    //HttpRequest.getData("hell");

    //qmlRegisterType<TestModel>("TestModel", 1, 0, "Testss");

    //qDebug() << qmlRegisterType<QJsonModel>();

    //QJsonModel js;
    //js.load("json.txt");
    //qDebug() << js.columnCount();
    qmlRegisterType<DictionaryModel>("Model", 1, 0, "DictionaryModel");
    qmlRegisterType<HeadwordEntry>("Model", 1, 0, "HeadwordEntry");

    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();

    //context->setContextProperty("js", &js);
    context->setContextProperty("HttpRequest", &HttpRequest);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
