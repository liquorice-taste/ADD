#ifndef HEADWORDENTRYLIST_H
#define HEADWORDENTRYLIST_H

#include <QObject>
#include <QVector>
#include <QVariant>
#include <QAbstractListModel>
#include <QDebug>

struct EntryItem{
    QList<QString> p_etymologies;
    //QList<Sense> p_sensesList;
};

class EntryList : public QObject
{
    Q_OBJECT
public:
    explicit EntryList(QObject *parent = nullptr);

    QList<EntryItem> items() const;

    bool setItemAt(int index, const EntryItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

private:
    QList<EntryItem> pItems;
};


struct LexicalAbstractEntryItem{
    QString p_language;
    QString p_lexicalCathegory;
    QString p_text;
    //QVector<Entry> p_entries;
};

struct LexicalEntryItem : LexicalAbstractEntryItem{
    //pronunciations
};
struct LexicalThesaurusItem : LexicalAbstractEntryItem{
};


class LexicalEntryList : public QObject
{
    Q_OBJECT
public:
    explicit LexicalEntryList(QObject *parent = nullptr);

    QList<LexicalEntryItem> items() const;

    bool setItemAt(int index, const LexicalEntryItem &item);
    void addItem(LexicalEntryItem &item);
    void addItem(QString p_language, QString p_lexicalCathegory, QString p_text);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

private:
    QList<LexicalEntryItem> pItems;
};



struct HeadwordAbstractEntryItem{
    int p_id;
    QString p_language;
    QString p_word;
    LexicalEntryList *p_lexicalEntries;
};

struct HeadwordThesaurusItem : public HeadwordAbstractEntryItem{

};

struct HeadwordEntryItem : public HeadwordAbstractEntryItem{
    //pronunciation list
};

class HeadwordEntryList : public QObject
{
    Q_OBJECT
public:
    explicit HeadwordEntryList(QObject *parent = nullptr);

    QList<HeadwordEntryItem> items() const;

    bool setItemAt(int index, const HeadwordEntryItem &item);
    void addItem(HeadwordEntryItem &item);
    void addItem(int p_id, QString p_language, QString p_word, LexicalEntryList *p_lexicalEntries);


signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();
public slots:
    void setList(const QList<HeadwordEntryItem>& hei);

private:
    QList<HeadwordEntryItem> pItems;
};

#endif // HEADWORDENTRYLIST_H
