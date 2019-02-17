#ifndef HEADWORDENTRYLIST_H
#define HEADWORDENTRYLIST_H

#include <QObject>
#include <QVector>
#include <QVariant>
#include <QAbstractListModel>

struct LexicalEntryItem{
    QString p_language;
    QString p_lexicalCathegory;
    QString p_text;
    //QVector<Entry> entriesList;
};


class LexicalEntryList : public QObject
{
    Q_OBJECT
public:
    explicit LexicalEntryList(QObject *parent = nullptr);

    QList<LexicalEntryItem> items() const;

    bool setItemAt(int index, const LexicalEntryItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem();
    void removeCompletedItems();

private:
QList<LexicalEntryItem> pItems;
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
        TextRole
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

struct HeadwordEntryItem{
    int p_id;
    QString p_language;
    QString p_word;
    LexicalEntryList *p_lexicalEntries;
};

class HeadwordEntryList : public QObject
{
    Q_OBJECT
public:
    explicit HeadwordEntryList(QObject *parent = nullptr);

    QList<HeadwordEntryItem> items() const;

    bool setItemAt(int index, const HeadwordEntryItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem();
    void removeCompletedItems();

private:
QList<HeadwordEntryItem> pItems;
};

#endif // HEADWORDENTRYLIST_H
