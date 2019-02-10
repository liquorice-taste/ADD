#ifndef DICTIONARYMODEL_H
#define DICTIONARYMODEL_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>

#include "requestmodel.h"

class DictionaryModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<HeadwordEntry> data READ data NOTIFY dataChanged)
    Q_CLASSINFO("DefaultProperty", "data")

public:
    explicit DictionaryModel(QObject *parent = nullptr);
    QQmlListProperty<HeadwordEntry> data();

signals:
    void dataChanged();
public slots:

private:
    static void appendData(QQmlListProperty<HeadwordEntry> *list, HeadwordEntry *value);
    void clearData(QQmlListProperty<HeadwordEntry> *list);
    static int countData(QQmlListProperty<HeadwordEntry> *list);
    static HeadwordEntry *atData(QQmlListProperty<HeadwordEntry> *list, int index);

    QList<HeadwordEntry*> p_data;
};

#endif // DICTIONARYMODEL_H
