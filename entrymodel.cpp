#include "dicmodel.h"

EntryModel::EntryModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}


int EntryModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant EntryModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const EntryItem item = mList->items().at(index.row());
    switch (role) {
    case EtymologiesRole:
        return QVariant(item.p_etymologies);
    //case SensesListRole:
        //return QVariant(item.p_senses);

    }

    return QVariant();
}

bool EntryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    EntryItem item = mList->items().at(index.row());
    switch (role) {
    case EtymologiesRole:
        //item.p_etymologies = value.toList();
        break;

    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags EntryModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> EntryModel::roleNames() const
{
    QHash<int, QByteArray> names;
    //names[LanguageRole] = "language";
    //names[LexicalCathegoryRole] = "lexicalcathegory";
    //names[TextRole] = "text";
    return names;
}

EntryList *EntryModel::list() const
{
    return mList;
}

void EntryModel::setList(EntryList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &EntryList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &EntryList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &EntryList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &EntryList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
