#include "headwordentrylist.h"

#include <QVariant>


EntryList::EntryList(QObject *parent) : QObject(parent)
{
    //LexicalEntryList *s1 = new LexicalEntryList();
    /*EntryItem it;
    pItems.append(it);
    pItems.append(it);*/
}

QList<EntryItem> EntryList::items() const
{
    return pItems;
}

bool EntryList::setItemAt(int index, const EntryItem &item)
{
    if (index < 0 || index >= pItems.size())
        return false;

    //const EntryItem &oldItem = pItems.at(index);
    //if (item.p_language == oldItem.p_language && item.p_lexicalCathegory == oldItem.p_lexicalCathegory && item.p_text == oldItem.p_text)
        //return false;

    pItems[index] = item;
    return true;
}


LexicalEntryList::LexicalEntryList(QObject *parent) : QObject(parent)
{
    //LexicalEntryList *s1 = new LexicalEntryList();
    /*LexicalEntryItem it;
    it.p_text = "wd";
    it.p_language = "dewd";
    it.p_lexicalCathegory = "dew";
    pItems.append(it);*/
    //pItems.append(it);
}

QList<LexicalEntryItem> LexicalEntryList::items() const
{
    return pItems;
}

bool LexicalEntryList::setItemAt(int index, const LexicalEntryItem &item)
{
    if (index < 0 || index >= pItems.size())
        return false;

    const LexicalEntryItem &oldItem = pItems.at(index);
    if (item.p_language == oldItem.p_language && item.p_lexicalCathegory == oldItem.p_lexicalCathegory && item.p_text == oldItem.p_text)
        return false;

    pItems[index] = item;
    return true;
}

void LexicalEntryList::addItem(LexicalEntryItem &item)
{
    emit preItemAppended();
    pItems.append(item);
    emit postItemAppended();

}

void LexicalEntryList::addItem(QString p_language, QString p_lexicalCathegory, QString p_text)
{
    emit preItemAppended();
    LexicalEntryItem item;
    item.p_language = p_language;
    item.p_lexicalCathegory = p_lexicalCathegory;
    item.p_text = p_text;
    emit postItemAppended();
}

HeadwordEntryList::HeadwordEntryList(QObject *parent) : QObject(parent)
{
    LexicalEntryList *s1 = new LexicalEntryList();
    HeadwordEntryItem it;
    it.p_id = 0;
    it.p_word = "sw";
    it.p_language = "sw";
    it.p_lexicalEntries= s1;
    pItems.append(it);
    pItems.append(it);
}

QList<HeadwordEntryItem> HeadwordEntryList::items() const
{
    return pItems;

}

bool HeadwordEntryList::setItemAt(int index, const HeadwordEntryItem &item)
{
    if (index < 0 || index >= pItems.size())
        return false;

    const HeadwordEntryItem &oldItem = pItems.at(index);
    if (item.p_id == oldItem.p_id && item.p_language == oldItem.p_word && item.p_lexicalEntries == oldItem.p_lexicalEntries)
        return false;

    pItems[index] = item;
    return true;
}

void HeadwordEntryList::addItem(HeadwordEntryItem &item)
{
    emit preItemAppended();
    pItems.append(item);
    emit postItemAppended();
}

void HeadwordEntryList::addItem(int p_id, QString p_language, QString p_word, LexicalEntryList *p_lexicalEntries)
{
    emit preItemAppended();
    HeadwordEntryItem item;
    item.p_id = p_id;
    item.p_language = p_language;
    item.p_word = p_word;
    item.p_lexicalEntries = p_lexicalEntries;
    pItems.append(item);
    emit postItemAppended();
}

void HeadwordEntryList::setList(const QList<HeadwordEntryItem> &hei)
{
    pItems = QList<HeadwordEntryItem>(hei);
}

