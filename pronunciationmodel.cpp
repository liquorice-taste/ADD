#include "dicmodel.h"

PronunciationModel::PronunciationModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
    //connect(mList, &PronunciationList::postItemAppended, this, &PronunciationModel::endResetModel);
}


int PronunciationModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant PronunciationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const PronunciationItem item = mList->items().at(index.row());
    switch (role) {
    case AudioFileRole:
        return QVariant(item.p_audiofile);
    case PhoneticNotationRole:
        return QVariant(item.p_phoneticNotation);
    case PhoneticSpellingRole:
        return QVariant(item.p_phoneticSpelling);
    case RegionsRole:
        return QVariant(item.p_regions);
    case DialectsRole:
        return QVariant(item.p_dialects);
    }

    return QVariant();
}

Qt::ItemFlags PronunciationModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> PronunciationModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[AudioFileRole] = "audio";
    names[PhoneticNotationRole] = "phoneticNotation";
    names[PhoneticSpellingRole] = "phoneticSpelling";
    names[RegionsRole] = "regions";
    names[DialectsRole] = "dialects";
    return names;
}

PronunciationList *PronunciationModel::list() const
{
    return mList;
}

void PronunciationModel::setList(PronunciationList *list)
{
    emit beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &PronunciationList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &PronunciationList::postItemAppended, this, [=]() {
            endInsertRows();
        });

    }
    emit endResetModel();
}
