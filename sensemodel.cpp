#include "dicmodel.h"

SenseModel::SenseModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
    //connect(mList, &HeadwordEntryList::postItemAppended, this, &SenseModel::endResetModel);
}


int SenseModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant SenseModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const SenseItem item = mList->items().at(index.row());
    switch (role) {
    case DefinitionsRole:
        return QVariant(item.p_definitions);
    case RegionsRole:
        return QVariant(item.p_regions);
    case RegistersRole:
        return QVariant(item.p_registers);
    case PronunciationListRole:
        return QVariant::fromValue<QObject *>(item.p_pronunciations);
    case DomainsRole:
        return QVariant(item.p_domains);
    case ExampleListRole:
        return QVariant::fromValue<QObject *>(item.p_examples);
    }

    return QVariant();
}

Qt::ItemFlags SenseModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> SenseModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DefinitionsRole] = "definitions";
    names[RegionsRole] = "regions";
    names[RegistersRole] = "registers";
    names[PronunciationListRole] = "pronunciations";
    names[DomainsRole] = "domains";
    names[ExampleListRole] = "examples";
    return names;
}

SenseList *SenseModel::list() const
{
    return mList;
}

void SenseModel::setList(SenseList *list)
{
    emit beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &SenseList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &SenseList::postItemAppended, this, [=]() {
            endInsertRows();
        });

    }
    emit endResetModel();
}
