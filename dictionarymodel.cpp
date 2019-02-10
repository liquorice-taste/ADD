#include "dictionarymodel.h"

DictionaryModel::DictionaryModel(QObject *parent) : QObject(parent)
{
    HeadwordEntry *he = new HeadwordEntry(this);
    he->setProperty("language", "ENGLISH");
    he->setProperty("num", 12);
    p_data.append(he);
    he->setProperty("language", "ENGLISH");
    he->setProperty("num", 12);
    p_data.append(he);
    he->setProperty("language", "ENGLISH");
    he->setProperty("num", 12);
    p_data.append(he);

}


QQmlListProperty<HeadwordEntry> DictionaryModel::data()
{
    return QQmlListProperty<HeadwordEntry>(this, p_data)/*(static_cast<QObject *>(this),
                                           static_cast<void *>(&p_entries),
                                           &DictionaryModel::appendData,
                                           &DictionaryModel::countData,
                                           &DictionaryModel::atData,
                                           &DictionaryModel::clearData)*/;
}

void DictionaryModel::appendData(QQmlListProperty<HeadwordEntry> *list, HeadwordEntry *value)
{
    QList<HeadwordEntry*> *data = static_cast<QList<HeadwordEntry*> *>(list->data);
    data->append(value);
}

int DictionaryModel::countData(QQmlListProperty<HeadwordEntry> *list)
{
    QList<HeadwordEntry*> *data = static_cast<QList<HeadwordEntry*> *>(list->data);
    return data->size();
}

HeadwordEntry *DictionaryModel::atData(QQmlListProperty<HeadwordEntry> *list, int index)
{
    QList<HeadwordEntry*> *data = static_cast<QList<HeadwordEntry*> *>(list->data);
    return data->at(index);
}


void DictionaryModel::clearData(QQmlListProperty<HeadwordEntry> *list)
{
    QList<HeadwordEntry*> *entries = static_cast<QList<HeadwordEntry*> *>(list->data);
    qDeleteAll(entries->begin(), entries->end());
    entries->clear();
}


