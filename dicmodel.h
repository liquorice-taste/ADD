#ifndef DICMODEL_H
#define DICMODEL_H

#include <QAbstractListModel>
#include "headwordentrylist.h"

class DicModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(HeadwordEntryList *list READ list WRITE setList)

public:
    explicit DicModel(QObject *parent = nullptr);

    enum {
        IdRole = Qt::UserRole,
        LanguageRole,
        WordRole
    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    HeadwordEntryList *list() const;
    void setList(HeadwordEntryList *list);

private:
    HeadwordEntryList *mList;
};

#endif // DICMODEL_H
