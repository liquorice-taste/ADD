#include "headwordentrylist.h"

LexicalEntryModel::LexicalEntryModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{

}


int LexicalEntryModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
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
    }

    return QVariant();
}

bool LexicalEntryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    LexicalEntryItem item = mList->items().at(index.row());
    switch (role) {
    case LanguageRole:
        item.p_language = value.toString();
        break;
    case LexicalCathegoryRole:
        item.p_lexicalCathegory = value.toString();
        break;
    case TextRole:
        item.p_text = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
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
    names[TextRole] = "text";
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

        connect(mList, &LexicalEntryList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &LexicalEntryList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
