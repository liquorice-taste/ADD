#include "headwordentrylist.h"

#include <QVariant>


LexicalEntryList::LexicalEntryList(QObject *parent) : QObject(parent)
{
    //LexicalEntryList *s1 = new LexicalEntryList();
    pItems.append({ QStringLiteral("hey"), QStringLiteral("hoe"), QStringLiteral("hay")});
    pItems.append({ QStringLiteral("ff"), QStringLiteral("dd"), QStringLiteral("cc")});
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

void LexicalEntryList::appendItem()
{
    emit preItemAppended();

    LexicalEntryItem item;
    //item.p_id = 0;
    pItems.append(item);

    emit postItemAppended();
}

void LexicalEntryList::removeCompletedItems()
{
    for (int i = 0; i < pItems.size(); ) {
        if (pItems.at(i).p_language == "english") { //remove it later
            emit preItemRemoved(i);

            pItems.removeAt(i);

            emit postItemRemoved();
        } else {
            ++i;
        }
    }
}



HeadwordEntryList::HeadwordEntryList(QObject *parent) : QObject(parent)
{
    LexicalEntryList *s1 = new LexicalEntryList();
    pItems.append({ 0, QStringLiteral("Wash the car"), QStringLiteral("gfy"), s1 });
    pItems.append({ 1, QStringLiteral("Fix the sink"), QStringLiteral("gfy"), s1 });
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

void HeadwordEntryList::appendItem()
{
    emit preItemAppended();

    HeadwordEntryItem item;
    item.p_id = 0;
    pItems.append(item);

    emit postItemAppended();
}

void HeadwordEntryList::removeCompletedItems()
{
    for (int i = 0; i < pItems.size(); ) {
        if (pItems.at(i).p_id == 0) { //remove it later
            emit preItemRemoved(i);

            pItems.removeAt(i);

            emit postItemRemoved();
        } else {
            ++i;
        }
    }
}
