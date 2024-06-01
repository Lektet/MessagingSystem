#include "JsonSerializable.h"

#include <QDebug>

JsonSerializable::JsonSerializable()
{

}

QJsonDocument JsonSerializable::toJson()
{
    QJsonObject object;
    initRootObject(object);

    QJsonDocument document;
    document.setObject(object);

    return document;
}

bool JsonSerializable::fromJson(const QJsonDocument &doc)
{
    if(!doc.isObject()){
        qDebug() << "JSON document is not object";
        return false;
    }

    auto rootObject = doc.object();
    return initFromRootObject(rootObject);
}
