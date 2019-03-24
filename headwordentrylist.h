#ifndef HEADWORDENTRYLIST_H
#define HEADWORDENTRYLIST_H

#include <QObject>
#include <QVector>
#include <QVariant>
#include <QAbstractListModel>
#include <QDebug>

struct PronunciationItem{
    QString p_audiofile;
    QString p_phoneticNotation;
    QString p_phoneticSpelling;
    QString p_regions;
    QStringList p_dialects;
};

class PronunciationList : public QObject
{
    Q_OBJECT
public:
    explicit PronunciationList(QObject *parent = nullptr);

    QList<PronunciationItem> items() const;

    void addItem(PronunciationItem &item);
    void addItem(QString p_audiofile,
                 QString p_phoneticNotation,
                 QString p_phoneticSpelling,
                 QString p_regions,
                 QStringList p_dialects);
signals:
    void preItemAppended();
    void postItemAppended();
public slots:
    void setList(const QList<PronunciationItem>& hei);
private:
    QList<PronunciationItem> pItems;
};


struct ExampleItem {
    QStringList p_domains;
    QStringList p_definitions;
    QStringList p_regions;
    QStringList p_registers;
    QString p_text;
    //translation
};


class ExampleList : public QObject
{
    Q_OBJECT
public:
    explicit ExampleList(QObject *parent = nullptr);

    QList<ExampleItem> items() const;

    void addItem(const ExampleItem &item);
    void addItem(const QStringList &p_domains ,
                 const QStringList &p_definitions,
                 const QStringList &p_regions,
                 const QStringList &p_registers,
                 const QString &p_text);
signals:
    void preItemAppended();
    void postItemAppended();
public slots:
    void setList(const QList<ExampleItem>& hei);

private:
    QList<ExampleItem> pItems;
};


struct AbstractSenseItem{
    QStringList p_domains;
    ExampleList *p_examples;

};

struct SenseItem: AbstractSenseItem {
    QStringList p_definitions;
    QStringList p_regions;
    QStringList p_registers;
    //translations???
    //variantForms???
    PronunciationList *p_pronunciations;
};

struct ThesaurusSenseItem : AbstractSenseItem {

};

class SenseList : public QObject
{
    Q_OBJECT
public:
    explicit SenseList(QObject *parent = nullptr);

    QList<SenseItem> items() const;

    void addItem(const SenseItem &item);
    void addItem(const QStringList &p_domains,
                 ExampleList *examples,
                 const QStringList &p_definitions,
                 const QStringList &p_regions,
                 const QStringList &p_registers,
                 PronunciationList *p_pronunciations);
signals:
    void preItemAppended();
    void postItemAppended();
public slots:
    void setList(const QList<SenseItem>& hei);
private:
    QList<SenseItem> pItems;
};


struct AbstractEntryItem{
    QStringList p_etymologies;
    SenseList *senses;
};

struct EntryItem : AbstractEntryItem{
    PronunciationList *p_pronunciations;
};

struct ThesaurusEntryItem : AbstractEntryItem{
};



class EntryList : public QObject
{
    Q_OBJECT
public:
    explicit EntryList(QObject *parent = nullptr);

    QList<EntryItem> items() const;

    void addItem(EntryItem &item);
    void addItem(const QStringList &p_etymologies,
                 SenseList *senses,
                 PronunciationList *p_pronunciations);
signals:
    void preItemAppended();
    void postItemAppended();

public slots:
    void setList(const QList<EntryItem>& hei);

private:
    QList<EntryItem> pItems;
};


struct LexicalAbstractEntryItem{
    QString p_language;
    QString p_lexicalCathegory;
    QString p_text;
    EntryList *p_entries;
};

struct LexicalEntryItem : LexicalAbstractEntryItem{
    PronunciationList *pronunciation;
};
struct LexicalThesaurusItem : LexicalAbstractEntryItem{
};


class LexicalEntryList : public QObject
{
    Q_OBJECT
public:
    explicit LexicalEntryList(QObject *parent = nullptr);

    QList<LexicalEntryItem> items() const;

    void addItem(LexicalEntryItem &item);
    void addItem(QString p_language,
                 QString p_lexicalCathegory,
                 QString p_text,
                 EntryList *p_entries,
                 PronunciationList *pronunciation);

signals:
    void preItemAppended();
    void postItemAppended();
public slots:
    void setList(const QList<LexicalEntryItem>& hei);
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
    PronunciationList *pronunciations;
};

class HeadwordEntryList : public QObject
{
    Q_OBJECT
public:
    explicit HeadwordEntryList(QObject *parent = nullptr);

    QList<HeadwordEntryItem> items() const;

    void addItem(HeadwordEntryItem &item);
    void addItem(int p_id, QString p_language, QString p_word, LexicalEntryList *p_lexicalEntries);
signals:
    void preItemAppended();
    void postItemAppended();

public slots:
    void setList(const QList<HeadwordEntryItem>& hei);

private:
    QList<HeadwordEntryItem> pItems;
};

#endif // HEADWORDENTRYLIST_H
