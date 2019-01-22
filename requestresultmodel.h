#ifndef REQUESTRESULTMODEL_H
#define REQUESTRESULTMODEL_H

#include <QAbstractTableModel>

class RequestResultModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit RequestResultModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // REQUESTRESULTMODEL_H
