#ifndef DICTIONARYMODEL_H
#define DICTIONARYMODEL_H

#include <QObject>

class DictionaryModel : public QObject
{
    Q_OBJECT
public:
    explicit DictionaryModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DICTIONARYMODEL_H