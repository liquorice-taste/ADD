#include "headwordentrylist.h"

HeadwordEntryList::HeadwordEntryList(QObject *parent) : QObject(parent)
{
    pItems.append({ 0, QStringLiteral("Wash the car"), QStringLiteral("gfy") });
    pItems.append({ 1, QStringLiteral("Fix the sink"), QStringLiteral("gfy") });
}

QVector<HeadwordEntryItem> HeadwordEntryList::items() const
{
    return pItems;
}

bool HeadwordEntryList::setItemAt(int index, const HeadwordEntryItem &item)
{
    if (index < 0 || index >= pItems.size())
        return false;

    const HeadwordEntryItem &oldItem = pItems.at(index);
    if (item.p_id == oldItem.p_id && item.p_language == oldItem.p_word)
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
