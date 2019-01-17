#include "httprequest.h"

httpRequest::httpRequest(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &httpRequest::onResult);
}

void httpRequest::onResult(QNetworkReply *reply)
{
    if (reply->error()){
        qDebug() << "ERROR"<< reply->errorString();
    } else {


        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());

        // Taking from the document root object
        QJsonObject root = document.object();
        QJsonValue val = root.value("metadata");
        qDebug() << "total" <<  val["total"].toDouble();
        qDebug() << "sourceLanguage" <<  val["sourceLanguage"].toString();
        qDebug() << "provider" <<  val["provider"].toString() << "\n";

        QJsonValue jv = root.value("results");
        // If the value is an array, ...
        if(jv.isArray()){
            // ... then pick from an array of properties
            QJsonArray ja = jv.toArray();
            // Going through all the elements of the array ...
            for(int i = 0; i < ja.count(); i++){
                QJsonObject subtree = ja.at(i).toObject();
                // Taking the values of the properties and last name by adding them to textEdit
                qDebug() << "score" << subtree.value("score").toDouble();
                qDebug() << "word" << subtree.value("word").toString();
                qDebug() << "region" << subtree.value("region").toString();
                qDebug() << "id" << subtree.value("id").toString();
                qDebug() << "matchString" << subtree.value("matchString").toString() << "\n";
            }
        }
    }
}

void httpRequest::getData(QString word)
{
    QUrl url("https://od-api.oxforddictionaries.com/api/v1/search/en?q=" + word + "&prefix=false");
    QNetworkRequest request;
    request.setUrl(url);

    request.setRawHeader("Accept", "application/json");
    request.setRawHeader("app_id", "d873ec2b");
    request.setRawHeader("app_key", "9c529bb074cc4cef731a7764f172e5e2");

    manager->get(request);

}


