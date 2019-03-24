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
    case SensesListRole:
        return QVariant::fromValue<QObject *>(item.senses);
    }

    return QVariant();
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
    names[EtymologiesRole] = "etymologies";
    names[SensesListRole] = "senses";
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

    }

    endResetModel();
}
