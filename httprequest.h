#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringList>

#include <QtTest/QtTest>

#include "QJsonModel-master/qjsonmodel.h"

class httpRequest : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QJsonModel jmodel READ jmodel CONSTANT FINAL)
private:
    QNetworkAccessManager * manager;
    QJsonModel jsm;
public:
    explicit httpRequest(QObject *parent = nullptr);
    QJsonModel jmodel();
signals:
    void onReady();
    void jmodelChanged();
public slots:
    void onResult(QNetworkReply *reply);
    void getData(QString word);
};
#endif // HTTPREQUEST_H
