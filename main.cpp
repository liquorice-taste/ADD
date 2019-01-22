#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "httprequest.h"
#include "testmodel.h"

Q_DECLARE_METATYPE(QJsonModel)

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    httpRequest HttpRequest;
    HttpRequest.getData("hell");

    qmlRegisterType<TestModel>("TestModel", 1, 0, "Testss");

    qDebug() << qmlRegisterType<QJsonModel>();


    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("HttpRequest", &HttpRequest);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
