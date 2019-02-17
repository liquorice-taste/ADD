#ifndef HEADWORDENTRYLIST_H
#define HEADWORDENTRYLIST_H

#include <QObject>
#include <QVector>
#include <QVariant>

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
