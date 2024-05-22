#include "AbstractMessage.h"

#include <QDebug>

AbstractMessage::AbstractMessage()
{

}

QJsonDocument AbstractMessage::toJson()
{
    QJsonObject object;
    initRootObject(object);

    QJsonDocument document;
    document.setObject(object);

    return document;
}

bool AbstractMessage::fromJson(const QJsonDocument &doc)
{
    if(!doc.isObject()){
        qDebug() << "JSON document is not object";
        return false;
    }

    auto rootObject = doc.object();
    return initFromRootObject(rootObject);
}
