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
    HeadwordEntryList * headEntry = new HeadwordEntryList();
    dm.setList(headEntry);
    QObject::connect(&HttpRequest, &httpRequest::onReady,
                         &j, &jsonParser::setDocument);

    QObject::connect(&j, &jsonParser::sendDoc,
                         &dm, &DicModel::setList);

    QQuickStyle::setStyle("Material");

    qmlRegisterType<DicModel>("Model", 1, 0, "DicModel");
    qmlRegisterType<LexicalEntryModel>("Model", 1, 0, "LexicalEntryModel");
    qmlRegisterType<EntryModel>("Model", 1, 0, "EntryModel");
    qmlRegisterType<SenseModel>("Model", 1, 0, "SenseModel");
    qmlRegisterType<ExampleModel>("Model", 1, 0, "ExampleModel");
    qmlRegisterType<PronunciationModel>("Model", 1, 0, "PronunciationModel");


    qmlRegisterType<HeadwordEntryList>();//"Model", 1, 0, "HeadwordEntryList");
    qmlRegisterType<LexicalEntryList>();
    qmlRegisterType<EntryList>();
    qmlRegisterType<SenseList>();
    qmlRegisterType<ExampleList>();
    qmlRegisterType<PronunciationList>();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("headEntry"), headEntry);
    engine.rootContext()->setContextProperty("HttpRequest", &HttpRequest);
    engine.rootContext()->setContextProperty("dicModel", &dm);
    HttpRequest.getData("ace");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
