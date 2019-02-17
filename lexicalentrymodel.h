/*#ifndef LEXICALENTRYMODEL_H
#define LEXICALENTRYMODEL_H

#include <QAbstractListModel>
#include "headwordentrylist.h"

class LexicalEntryModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(LexicalEntryList *list READ list WRITE setList)

public:
    explicit LexicalEntryModel(QObject *parent = nullptr);

    enum {
        LanguageRole = Qt::UserRole,
        LexicalCathegoryRole,
        TextRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    LexicalEntryList *list() const;
    void setList(LexicalEntryList *list);

private:
    LexicalEntryList *mList;
};

#endif // LEXICALENTRYMODEL_H
*/
