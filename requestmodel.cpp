#include "requestmodel.h"

HeadwordEntry::HeadwordEntry(QObject *parent) : QObject(parent)
{

}

QString HeadwordEntry::language() const
{
    return p_language;
}


int HeadwordEntry::num() const
{
    return p_id;
}


QVector<QString> Example::definitions()
{
    return p_definitions;
}


QString Example::text()
{
    return p_text;
}
