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
        LanguageRole ,
        WordRole,
        LexicalEntryRole,
        PronunciationListRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

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
        EntriesRole,
        PronunciationListRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

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
        SensesListRole,
        PronunciationListRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    EntryList *list() const;
    void setList(EntryList *list);

private:
    EntryList *mList;
};



class SenseModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(SenseList *list READ list WRITE setList)

public:
    explicit SenseModel(QObject *parent = nullptr);

    enum {
        DomainsRole = Qt::UserRole,
        ExampleListRole,
        DefinitionsRole,
        RegionsRole,
        RegistersRole,
        PronunciationListRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    SenseList *list() const;
    void setList(SenseList *list);

private:
    SenseList *mList;
};


class ExampleModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(ExampleList *list READ list WRITE setList)

public:
    explicit ExampleModel(QObject *parent = nullptr);

    enum {
        DomainsRole = Qt::UserRole,
        DefinitionsRole,
        RegionsRole,
        RegistersRole,
        TextRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    ExampleList *list() const;
    void setList(ExampleList *list);

private:
    ExampleList *mList;
};





class PronunciationModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(PronunciationList *list READ list WRITE setList)

public:
    explicit PronunciationModel(QObject *parent = nullptr);

    enum {
        AudioFileRole = Qt::UserRole,
        PhoneticNotationRole,
        PhoneticSpellingRole,
        RegionsRole,
        DialectsRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    PronunciationList *list() const;
    void setList(PronunciationList *list);

private:
    PronunciationList *mList;
};

#endif // DICMODEL_H
