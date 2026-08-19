#ifndef MESSAGESCREATION_H
#define MESSAGESCREATION_H

#include <QString>

#include <QJsonObject>
#include <QJsonDocument>

#include "MessageType.h"

#include <QDebug>

namespace MessageUtils
{
    template<typename T>
    T createMessageFromJson(const QJsonDocument &document, bool* parseSuccess)
    {
        T message;
        if(!document.isObject()){
            qWarning() << "Json document is invalid";
            return message;
        }

        if(document.object().isEmpty()){
            qWarning() << "Json object is empty";
            return message;
        }

        *parseSuccess = message.fromJson(document);
        return message;
    }

    MessageType getMessageType(const QJsonDocument& document);

    QString getStringFromJsonObject(const QJsonObject& obj, const QString& key);
    bool getBoolFromJsonObject(const QJsonObject& obj, const QString& key);
    int getIntFromJsonObject(const QJsonObject& obj, const QString& key);
}

#endif // MESSAGESCREATION_H
