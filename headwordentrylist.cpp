#include "headwordentrylist.h"

#include <QVariant>


EntryList::EntryList(QObject *parent) : QObject(parent)
{
}

ExampleList::ExampleList(QObject *parent) : QObject(parent)
{
}

QList<EntryItem> EntryList::items() const
{
    return pItems;
}

void EntryList::addItem(EntryItem &item)
{
    emit preItemAppended();
    pItems.append(item);
    emit postItemAppended();
}

void EntryList::addItem(const QStringList &p_etymologies, SenseList *senses, PronunciationList *p_pronunciations)
{
    emit preItemAppended();
    EntryItem item;
    item.p_etymologies = p_etymologies;
    item.senses = senses;
    item.p_pronunciations = p_pronunciations;
    pItems.append(item);
    emit postItemAppended();
}

PronunciationList::PronunciationList(QObject *parent) : QObject(parent)
{
}
void PronunciationList::setList(const QList<PronunciationItem>& hei){
    pItems = QList<PronunciationItem>(hei);
};

QList<PronunciationItem> PronunciationList::items() const
{
    return pItems;
}

void ExampleList::setList(const QList<ExampleItem>& hei){
    pItems = QList<ExampleItem>(hei);
};

QList<ExampleItem> ExampleList::items() const
{
    return pItems;
}

void SenseList::setList(const QList<SenseItem>& hei){
    pItems = QList<SenseItem>(hei);
};

QList<SenseItem> SenseList::items() const
{
    return pItems;
}

void EntryList::setList(const QList<EntryItem>& hei){
    pItems = QList<EntryItem>(hei);
};


void LexicalEntryList::setList(const QList<LexicalEntryItem> &hei)
{
    pItems = QList<LexicalEntryItem>(hei);
}

LexicalEntryList::LexicalEntryList(QObject *parent) : QObject(parent)
{
}

QList<LexicalEntryItem> LexicalEntryList::items() const
{
    return pItems;
}

void LexicalEntryList::addItem(LexicalEntryItem &item)
{
    emit preItemAppended();
    pItems.append(item);
    emit postItemAppended();

}

void LexicalEntryList::addItem(QString p_language, QString p_lexicalCathegory, QString p_text, EntryList *p_entries, PronunciationList *pronunciation)
{
    emit preItemAppended();
    LexicalEntryItem item;
    item.p_language = p_language;
    item.p_lexicalCathegory = p_lexicalCathegory;
    item.p_text = p_text;
    item.p_entries = p_entries;
    item.pronunciation = pronunciation;
    pItems.append(item);
    emit postItemAppended();
}

HeadwordEntryList::HeadwordEntryList(QObject *parent) : QObject(parent)
{

}

SenseList::SenseList(QObject *parent) : QObject(parent)
{

}

QList<HeadwordEntryItem> HeadwordEntryList::items() const
{
    return pItems;
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


void PronunciationList::addItem(PronunciationItem &item)
{
    emit preItemAppended();
    pItems.append(item);
    emit postItemAppended();
}

void PronunciationList::addItem(QString p_audiofile, QString p_phoneticNotation, QString p_phoneticSpelling, QString p_regions, QStringList p_dialects)
{
    emit preItemAppended();
    PronunciationItem item;
    item.p_audiofile = p_audiofile;
    item.p_phoneticNotation = p_phoneticNotation;
    item.p_phoneticSpelling = p_phoneticSpelling;
    item.p_regions = p_regions;
    item.p_dialects = p_dialects;
    pItems.append(item);
    emit postItemAppended();
}

void ExampleList::addItem(const ExampleItem &item)
{
    emit preItemAppended();
    pItems.append(item);
    emit postItemAppended();
}

void ExampleList::addItem(const QStringList &p_domains,
                          const QStringList &p_definitions,
                          const QStringList &p_regions,
                          const QStringList &p_registers,
                          const QString &p_text)
{
    emit preItemAppended();
    ExampleItem item;
    item.p_domains = p_domains;
    item.p_definitions = p_definitions;
    item.p_regions = p_regions;
    item.p_registers = p_registers;
    item.p_text = p_text;
    pItems.append(item);
    emit postItemAppended();
}

void SenseList::addItem(const SenseItem &item)
{
    emit preItemAppended();
    pItems.append(item);
    emit postItemAppended();
}

void SenseList::addItem(const QStringList &p_domains, ExampleList *examples, const QStringList &p_definitions, const QStringList &p_regions, const QStringList &p_registers, PronunciationList *p_pronunciations)
{
    emit preItemAppended();
    SenseItem item;
    item.p_domains = p_domains;
    item.p_examples = examples;
    item.p_definitions = p_definitions;
    item.p_regions = p_regions;
    item.p_registers = p_registers;
    item.p_pronunciations = p_pronunciations;
    pItems.append(item);
    emit postItemAppended();
}
