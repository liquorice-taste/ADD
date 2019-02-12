#ifndef HEADWORDENTRYLIST_H
#define HEADWORDENTRYLIST_H

#include <QObject>
#include <QVector>

struct HeadwordEntryItem{
    int p_id;
    QString p_language;
    QString p_word;
    //QVector<LexicalEntry> lexicalEntries;
};


class HeadwordEntryList : public QObject
{
    Q_OBJECT
public:
    explicit HeadwordEntryList(QObject *parent = nullptr);

    QVector<HeadwordEntryItem> items() const;

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
QVector<HeadwordEntryItem> pItems;
};

#endif // HEADWORDENTRYLIST_H
