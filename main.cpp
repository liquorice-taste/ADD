#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QDebug>
#include <QQmlContext>
#include <QQuickStyle>
#include "httprequest.h"
#include "dicmodel.h"
#include "requestmodel.h"
#include "jsonparser.h"

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    httpRequest HttpRequest;
    jsonParser j;
    DicModel dm;
    HeadwordEntryList headEntry;
    QObject::connect(&HttpRequest, &httpRequest::onReady,
                         &j, &jsonParser::setDocument);

    QObject::connect(&j, &jsonParser::sendDoc,
                         &headEntry, &HeadwordEntryList::setList);

    HttpRequest.getData("hell");

    //j.setDocument(HttpRequest.getReply());
    //j.parseDoc();

    //httpRequest HttpRequest;
    //HttpRequest.getData("hell");
    QQuickStyle::setStyle("Material");
    qmlRegisterType<DicModel>("Model", 1, 0, "DicModel");
    qmlRegisterType<LexicalEntryModel>("Model", 1, 0, "LexicalEntryModel");

    qmlRegisterType<HeadwordEntryList>();//"Model", 1, 0, "HeadwordEntryList");
    qmlRegisterType<LexicalEntryList>();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("headEntry"), &headEntry);
    engine.rootContext()->setContextProperty("HttpRequest", &HttpRequest);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
