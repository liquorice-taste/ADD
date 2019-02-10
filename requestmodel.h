#ifndef REQUESTMODEL_H
#define REQUESTMODEL_H

#include <QObject>
#include <QString>
#include <QVector>


class Example : public QObject {

    Q_OBJECT
    Q_PROPERTY(QVector<QString> definitions READ definitions)
    Q_PROPERTY(QString text READ text)
private:
    QVector<QString> p_definitions;
    QVector<QString> p_domains;
    QVector<QString> p_regions;
    QVector<QString> p_registers;
    QString p_text;
public:

    QVector<QString> definitions();
    QString text();

};

class Sense{
private:
    int id;
    QVector<QString> definitions;
    QVector<QString> domains;
    QVector<Example> examplesList;
    QVector<QString> regions;
    QVector<Sense> subsenses;
    QVector<QString> registers;
public:
};

class Entry{
private:
    QVector<QString> etymologies;
    QVector<Sense> sensesList;
public:
};

class LexicalEntry{
private:
    QString language;
    QString lexicalCathegory;
    QString text;
    QVector<Entry> entriesList;
public:
};

class HeadwordEntry : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString language READ language)
    Q_PROPERTY(int num READ num)

public:
    explicit HeadwordEntry(QObject *parent = 0);
    QString language() const;
    int num() const;
private:
    int p_id;
    QString p_language;
    QString word;
    //QVector<LexicalEntry> lexicalEntries;
};



#endif // REQUESTMODEL_H
