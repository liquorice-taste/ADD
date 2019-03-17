#include "dicmodel.h"

DicModel::DicModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
    //connect(mList, &HeadwordEntryList::postItemAppended, this, &DicModel::endResetModel);
}


int DicModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant DicModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const HeadwordEntryItem item = mList->items().at(index.row());
    switch (role) {
    case IdRole:
        return QVariant(item.p_id);
    case LanguageRole:
        return QVariant(item.p_language);
    case WordRole:
        return QVariant(item.p_word);
    case LexicalEntryRole:
        return QVariant::fromValue<QObject *>(item.p_lexicalEntries);
    }

    return QVariant();
}

bool DicModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    HeadwordEntryItem item = mList->items().at(index.row());
    switch (role) {
    case IdRole:
        item.p_id = value.toInt();
        break;
    case LanguageRole:
        item.p_language = value.toString();
        break;
    case WordRole:
        item.p_word = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags DicModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> DicModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[IdRole] = "id";
    names[LanguageRole] = "language";
    names[WordRole] = "word";
    names[LexicalEntryRole] = "lexicalEntries";
    return names;
}

HeadwordEntryList *DicModel::list() const
{
    return mList;
}

void DicModel::setList(HeadwordEntryList *list)
{
    emit beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &HeadwordEntryList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &HeadwordEntryList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &HeadwordEntryList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &HeadwordEntryList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }
    emit endResetModel();
}
