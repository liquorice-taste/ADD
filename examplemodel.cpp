#include "dicmodel.h"

ExampleModel::ExampleModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
    //connect(mList, &ExampleList::postItemAppended, this, &ExampleModel::endResetModel);
}


int ExampleModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant ExampleModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const ExampleItem item = mList->items().at(index.row());
    switch (role) {
    case DomainsRole:
        return QVariant(item.p_domains);
    case DefinitionsRole:
        return QVariant(item.p_definitions);
    case RegionsRole:
        return QVariant(item.p_regions);
    case RegistersRole:
        return QVariant(item.p_registers);
    case TextRole:
        return QVariant(item.p_text);
    }

    return QVariant();
}

Qt::ItemFlags ExampleModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> ExampleModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DomainsRole] = "domains";
    names[DefinitionsRole] = "definitions";
    names[RegionsRole] = "regions";
    names[RegistersRole] = "registers";
    names[TextRole] = "ltext";
    return names;
}

ExampleList *ExampleModel::list() const
{
    return mList;
}

void ExampleModel::setList(ExampleList *list)
{
    emit beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &ExampleList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &ExampleList::postItemAppended, this, [=]() {
            endInsertRows();
        });

    }
    emit endResetModel();
}
