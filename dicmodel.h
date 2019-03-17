#ifndef DICMODEL_H
#define DICMODEL_H

#include <QAbstractListModel>
#include "headwordentrylist.h"
#include <QVariant>
#include <QVariantList>

class DicModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(HeadwordEntryList *list READ list WRITE setList)

public:
    explicit DicModel(QObject *parent = nullptr);

    enum {
        IdRole = Qt::UserRole,
        LanguageRole,
        WordRole,
        LexicalEntryRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    HeadwordEntryList *list() const;
    void setList(HeadwordEntryList *list);

private:
    HeadwordEntryList *mList;
};


class LexicalEntryModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(LexicalEntryList *list READ list WRITE setList)

public:
    explicit LexicalEntryModel(QObject *parent = nullptr);

    enum {
        LanguageRole = Qt::UserRole,
        LexicalCathegoryRole,
        TextRole,
        EntriesRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    LexicalEntryList *list() const;
    void setList(LexicalEntryList *list);

private:
    LexicalEntryList *mList;
};


class EntryModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(EntryList *list READ list WRITE setList)

public:
    explicit EntryModel(QObject *parent = nullptr);

    enum {
        EtymologiesRole = Qt::UserRole,
        SensesListRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    EntryList *list() const;
    void setList(EntryList *list);

private:
    EntryList *mList;
};

#endif // DICMODEL_H
