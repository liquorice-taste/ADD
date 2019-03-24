#include "jsonparser.h"

jsonParser::jsonParser(QObject *parent) : QObject(parent)
{

}


void jsonParser::setDocument(const QJsonObject &doc)
{
    jDoc = doc;
    emit parseDoc();
}

void jsonParser::parseDoc()
{
    HeadwordEntryList hlist;
    QJsonValue results = jDoc.value("results");
    if(results.isArray()){

        QJsonArray resultsArr = results.toArray();
        //results
        for(int i = 0; i < resultsArr.count(); i++){
            QJsonObject result = resultsArr.at(i).toObject();
            LexicalEntryList *llist = new LexicalEntryList();
            QJsonValue lexicalEntries = result.value("lexicalEntries");
            if (lexicalEntries.isArray()) {
                QJsonArray lexicalEntriesArray = lexicalEntries.toArray();
                //lexicalEntries
                for(int i = 0; i < lexicalEntriesArray.count(); i++) {
                    QJsonObject lexicalEntry = lexicalEntriesArray.at(i).toObject();
                    QVariantMap mmap = result.toVariantMap();

                    EntryList *elist = new EntryList();
                    PronunciationList *plist = new PronunciationList();
                    QJsonValue entries = lexicalEntry.value("entries").toArray();
                    if (entries.isArray()) {
                        QJsonArray entriesArray = entries.toArray();
                        //entries
                        for(int i = 0; i < entriesArray.count(); i++) {
                            QJsonObject entry = entriesArray.at(i).toObject();
                            SenseList *slist1 = new SenseList();
                            PronunciationList *plist1 = new PronunciationList();
                            QJsonArray etymologies = entry.value("etymologies").toArray();
                            QStringList etymologyList;
                            //etymologies
                            for(int i = 0; i < etymologies.count(); i++) {
                                etymologyList.append(etymologies.at(i).toString());
                            }

                            QJsonValue senses = entry.value("senses");
                            if (senses.isArray()) {
                                QJsonArray sensesArray = senses.toArray();
                                ExampleList *elist = new ExampleList();
                                PronunciationList *plist = new PronunciationList();
                                //senses
                                for (int i = 0; i < sensesArray.count(); i++) {
                                    QJsonObject sense = sensesArray.at(i).toObject();

                                    QJsonValue examples = sense.value("examples");
                                    if (examples.isArray()) {
                                        QJsonArray examplesArray = examples.toArray();
                                        //examples
                                        for (int i = 0; i < examplesArray.count(); i++) {
                                            QJsonObject example = examplesArray.at(i).toObject();
                                            elist->addItem(parseStringList(example.value("domains").toArray()),
                                                           parseStringList(example.value("definitions").toArray()),
                                                           parseStringList(example.value("regions").toArray()),
                                                           parseStringList(example.value("registers").toArray()),
                                                           example.value("text").toString());
                                        }
                                    }

                                    QJsonValue pronunciations = sense.value("pronunciations");
                                    if (pronunciations.isArray()) {
                                        QJsonArray pronunciationsArray = pronunciations.toArray();
                                        for(int i = 0; i < pronunciationsArray.count(); i++) {
                                            QJsonObject pronunciation = pronunciationsArray.at(i).toObject();
                                            plist->addItem(pronunciation.value("audioFile").toString(),
                                                           pronunciation.value("phoneticNotation").toString(),
                                                           pronunciation.value("phoneticSpelling").toString(),
                                                           pronunciation.value("regions").toString(),
                                                           parseStringList(pronunciation.value("dialects").toArray())
                                                           );
                                        }
                                    }
                                    slist1->addItem(parseStringList(sense.value("domains").toArray()),
                                                    elist,
                                                    parseStringList(sense.value("definitions").toArray()),
                                                    parseStringList(sense.value("regions").toArray()),
                                                    parseStringList(sense.value("registers").toArray()),
                                                    plist);
                                }
                            }
                            //pronunciations
                            QJsonValue pronunciations = lexicalEntry.value("pronunciations").toArray();
                            if (pronunciations.isArray()) {
                                QJsonArray pronunciationsArray = pronunciations.toArray();
                                for(int i = 0; i < pronunciationsArray.count(); i++) {
                                    QJsonObject pronunciation = pronunciationsArray.at(i).toObject();
                                    plist1->addItem(pronunciation.value("audioFile").toString(),
                                                   pronunciation.value("phoneticNotation").toString(),
                                                   pronunciation.value("phoneticSpelling").toString(),
                                                   pronunciation.value("regions").toString(),
                                                   parseStringList(pronunciation.value("dialects").toArray())
                                                   );
                                }
                            }
                            elist->addItem(etymologyList, slist1, plist1);

                        }
                    }
                    QJsonValue pronunciations = result.value("pronunciations").toArray();
                    if (pronunciations.isArray()) {
                        QJsonArray pronunciationsArray = pronunciations.toArray();
                        for(int i = 0; i < pronunciationsArray.count(); i++) {
                            QJsonObject pronunciation = pronunciationsArray.at(i).toObject();
                            //QStringList l = parseStringList(pronunciation.value("dialects").toArray());
                            plist->addItem(pronunciation.value("audioFile").toString(),
                                           pronunciation.value("phoneticNotation").toString(),
                                           pronunciation.value("phoneticSpelling").toString(),
                                           pronunciation.value("regions").toString(),
                                           parseStringList(pronunciation.value("dialects").toArray())
                                           );
                        }
                    }
                    llist->addItem(lexicalEntry.value("language").toString(), lexicalEntry.value("lexicalCategory").toString(), lexicalEntry.value("text").toString(), elist, plist);
                }
            }
            hlist.addItem(result.value("id").toInt(), result.value("language").toString(), result.value("word").toString(),llist);
        }
    }

    emit sendDoc(&hlist);

}

QStringList jsonParser::parseStringList(const QJsonArray &array)
{
    if (!array.empty()) {
        QStringList arrList;
        for(int i = 0; i < array.count(); i++) {
            arrList.append(array.at(i).toString());
        }
        return arrList;
    }
    return QStringList();

}

/*
 * EXAMPLE SHIT
 *

    plist->addItem(parseStringList(pronunciation.value("domains").toArray()),
                   parseStringList(pronunciation.value("definitions").toArray()),
                   parseStringList(pronunciation.value("regions").toArray()),
                   parseStringList(pronunciation.value("registers").toArray()),
                   pronunciation.value("text"));


*/
