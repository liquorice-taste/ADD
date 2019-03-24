#include "dicmodel.h"

LexicalEntryModel::LexicalEntryModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}


int LexicalEntryModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant LexicalEntryModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const LexicalEntryItem item = mList->items().at(index.row());
    switch (role) {
    case LanguageRole:
        return QVariant(item.p_language);
    case LexicalCathegoryRole:
        return QVariant(item.p_lexicalCathegory);
    case TextRole:
        return QVariant(item.p_text);
    case EntriesRole:
        return QVariant::fromValue<QObject *>(item.p_entries);
    }

    return QVariant();
}

Qt::ItemFlags LexicalEntryModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> LexicalEntryModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[LanguageRole] = "language";
    names[LexicalCathegoryRole] = "lexicalcathegory";
    names[TextRole] = "ltext";
    names[EntriesRole] = "entries";
    return names;
}

LexicalEntryList *LexicalEntryModel::list() const
{
    return mList;
}

void LexicalEntryModel::setList(LexicalEntryList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &LexicalEntryList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &LexicalEntryList::postItemAppended, this, [=]() {
            endInsertRows();
        });
    }

    endResetModel();
}
