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


class httpRequest : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager * manager;
public:
    explicit httpRequest(QObject *parent = nullptr);
signals:
    void onReady();
public slots:
    void onResult(QNetworkReply *reply);
    void getData(QString word);
};
#endif // HTTPREQUEST_H
