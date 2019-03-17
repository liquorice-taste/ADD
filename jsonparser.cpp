#include "jsonparser.h"

jsonParser::jsonParser(QObject *parent) : QObject(parent)
{

}


void jsonParser::setDocument(const QJsonObject &doc)
{
    jDoc = doc;
    //jDoc = QJsonDocument::fromJson(*doc);
    //qDebug() << "a";
    //HeadwordEntryList *dic = parseDoc();
    emit parseDoc();

}

void jsonParser::parseDoc()
{
    //QJsonObject root = jDoc.object();

    QStringList list = jDoc.keys();
    //DicModel * dic = new DicModel();
    HeadwordEntryList * hlist = new HeadwordEntryList();

    QJsonValue jv = jDoc.value("results");
    // If the value is an array, ...
    if(jv.isArray()){

        // ... then pick from an array of properties
        QJsonArray ja = jv.toArray();

        // Going through all the elements of the array ...
        for(int i = 0; i < ja.count(); i++){
            QJsonObject subtree = ja.at(i).toObject();
            QVariantMap map = subtree.toVariantMap();
            LexicalEntryList *llist = new LexicalEntryList();
            hlist->addItem(subtree.value("id").toInt(), subtree.value("language").toString(), subtree.value("word").toString(), llist);
            QJsonValue jm = jDoc.value("lexicalEntries");
            if (jm.isArray()) {
                QJsonArray jl = jm.toArray();
                for(int i = 0; i < jl.count(); i++) {
                    QJsonObject lsubtree = jl.at(i).toObject();
                    QVariantMap mmap = subtree.toVariantMap();
                    //EntryList *elist = new EntryList();
                    llist->addItem(subtree.value("language").toString(), subtree.value("lexicalCathegory").toString(), subtree.value("text").toString());
                }

            }

            //for (auto & i: map){
            /*qDebug() << subtree.keys() << endl << endl;
            //}
            QVariantMap lmap = map.value("lexicalEntries").toMap();
            qDebug() << "score" << subtree.value("score").toDouble();
            qDebug() << "word" << subtree.value("word").toString();
            qDebug() << "region" << subtree.value("region").toString();
            qDebug() << "id" << subtree.value("id").toString();
            qDebug() << "matchString" << subtree.value("matchString").toString() << "\n";*/

        }
    }

    emit sendDoc(hlist->items());
    //QJsonValue val = jDoc.value("metadata");
    //qDebug() << "provider" <<  val["provider"].toString() << "\n";
    /*
    QVariantMap m = jDoc.toVariantMap();
    qDebug() << m.find("examples").value();*/
    /*for (auto & z : m) {

        qDebug() << z;
    }*/
    //qDebug() << m.find("results").value();
    //qDebug() << m.find("id").value();
    //if (!j.empty()) {
    //qDebug() << "id";
    //QJsonValue val = jDoc.value("metadata");
    //qDebug() << "id" <<  val["provider"].toString() << "\n";
    // }
}
