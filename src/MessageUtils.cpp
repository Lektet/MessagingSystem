#include "MessageUtils.h"

const QString TYPE_KEY = "Type";

MessageType MessageUtils::getMessageType(const QJsonDocument &document)
{
    if(!document.isObject()){
        qWarning() << "Json document is invalid";
        return MessageType::Invalid;
    }

    auto object = document.object();
    if(object.isEmpty()){
        qWarning() << "Json object is empty";
        return MessageType::Invalid;
    }

    if(!object.contains(TYPE_KEY)){
        qWarning() << "JSON object is invalid";
        return MessageType::Invalid;
    }

    return messageTypeFromString(object.value(TYPE_KEY).toString());
}

QString MessageUtils::getStringFromJsonObject(const QJsonObject &obj, const QString &key)
{
    if(!obj.contains(key)){
        qDebug() << "Json object contains no key: "  << key;
        return QString();
    }

    auto val = obj.value(key);
    if(!val.isString()){
        qDebug() << "Json value of \"" << key << "\" is not a string";
    }

    return val.toString();
}

bool MessageUtils::getBoolFromJsonObject(const QJsonObject &obj, const QString &key)
{
    if(!obj.contains(key)){
        qDebug() << "Json object contains no key: "  << key;
        return false;
    }

    auto val = obj.value(key);
    if(!val.isBool()){
        qDebug() << "Json value of \"" << key << "\" is not bool";
    }

    return val.toBool();
}

int MessageUtils::getIntFromJsonObject(const QJsonObject &obj, const QString &key)
{
    if(!obj.contains(key)){
        qDebug() << "Json object contains no key: "  << key;
        return false;
    }

    auto val = obj.value(key);
    if(!val.isDouble()){
        qDebug() << "Json value of \"" << key << "\" is not double";
    }

    return val.toInt();
}
