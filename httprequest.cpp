#include "httprequest.h"

httpRequest::httpRequest(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &httpRequest::onResult);
}

QByteArray httpRequest::getReply()
{
    return jsonReply;
}

void httpRequest::onResult(QNetworkReply *nreply)
{
    qDebug() << "good to go!";
    if (nreply->error()){
            qDebug() << "ERROR"<< nreply->errorString();
        } else {
            QJsonDocument document = QJsonDocument::fromJson(nreply->readAll());
            if (!document.isNull()){
                QJsonObject root = QJsonObject(document.object());
                //QByteArray* arr = new QByteArray(nreply->readAll());
                emit onReady(root);
                //QByteArray *b =  new QByteArray(reply->readAll());
                /*if (jsm.load(reply)) {
                    qDebug() << "caroline sucks!";
                };*/
            } else {
                qDebug() << "caroline sucks";
            }
    }


/*
    qDebug() << "reply recieved";
    //reply = nreply;
    QVariant statusCode = nreply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
    if ( !statusCode.isValid() )
    return;

    int status = statusCode.toInt();

    if ( status != 200 )
    {
        QString reason = nreply->attribute( QNetworkRequest::HttpReasonPhraseAttribute ).toString();
        qDebug() << reason;
    }


    if (nreply != nullptr && nreply->size() != 0){
        if (nreply->error() == QNetworkReply::NoError){
            jsonReply = nreply->readAll();
            if (jsonReply != nullptr && jsonReply.size() != 0) {
                qDebug() << "no error";
                QByteArray * arr = new QByteArray(nreply->readAll());
                QJsonDocument jDoc = QJsonDocument::fromJson(nreply->readAll());
                QJsonObject root = jDoc.object();

                QStringList list = root.keys();
                for (auto &i: list) {
                    qDebug() << root.value(i);
                }
                QJsonValue val = root.value("metadata");
                qDebug() << "provider" <<  val["provider"].toString() << "\n";
                qDebug() << root.empty();
                emit onReady(arr);
            }
        } else {
               qDebug() << nreply->errorString();
        }
    }

*/
/*
    if (reply->error()){
        qDebug() << "ERROR"<< nreply->errorString();
    } else {
        QJsonDocument document = QJsonDocument::fromJson(nreply->readAll());
        //qDebug() << document;
        if (!document.isNull()){
            QJsonObject root = document.object();

            //QByteArray *b =  new QByteArray(reply->readAll());
            if (jsm.load(reply)) {
                qDebug() << "caroline sucks!";
            };
        } else {
            qDebug() << "caroline sucks";
        }
    }

    //qDebug() << "колонки" << jsm.columnCount();

        QStringList list = root.keys();
        for (auto &i: list) {
            qDebug() << root.value(i);
        }
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
                QVariantMap map = subtree.toVariantMap();
                //for (auto & i: map){
                qDebug() << subtree.keys() << endl << endl;
                //}

                qDebug() << "score" << subtree.value("score").toDouble();
                qDebug() << "word" << subtree.value("word").toString();
                qDebug() << "region" << subtree.value("region").toString();
                qDebug() << "id" << subtree.value("id").toString();
                qDebug() << "matchString" << subtree.value("matchString").toString() << "\n";

            }
        }
    }
    */
}

void httpRequest::getData(QString word)
{
    QUrl url("https://od-api.oxforddictionaries.com:443/api/v1/entries/en/" + word);

    QNetworkRequest request;
    request.setUrl(url);

    request.setRawHeader("Accept", "application/json");
    request.setRawHeader("app_id", "d873ec2b");
    request.setRawHeader("app_key", "f0b838db12c659241648b18d7b060d14");

    manager->get(request);
    qDebug() << "req sent";

}


