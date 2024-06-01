#ifndef MESSAGEBASE_H
#define MESSAGEBASE_H

#include <QJsonDocument>
#include <QJsonObject>

struct JsonSerializable
{
public:
    explicit JsonSerializable();

    virtual QJsonDocument toJson();
    virtual bool fromJson(const QJsonDocument &doc);

protected:
    virtual void initRootObject(QJsonObject &rootObj) = 0;
    virtual bool initFromRootObject(const QJsonObject &rootObj) = 0;
};

#endif // MESSAGEBASE_H
