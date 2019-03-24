#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringList>

#include <QNetworkReply>

#include "dicmodel.h"


class jsonParser : public QObject
{
    Q_OBJECT
public:
    explicit jsonParser(QObject *parent = nullptr);
    void parseDoc();
    QStringList parseStringList(const QJsonArray &array);
signals:
    void sendDoc(HeadwordEntryList *);
public slots:
    void setDocument(const QJsonObject &doc);
private:
    QJsonObject jDoc;
    QNetworkReply *rep;
};

#endif // JSONPARSER_H
