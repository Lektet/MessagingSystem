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

QString MessageUtils::getStringFromJsonObject(const QJsonObject &obj, const QString &key, bool &success)
{
    if(!obj.contains(key)){
        success = false;
        qWarning() << "Json object contains no key: "  << key;
        return QString();
    }

    auto val = obj.value(key);
    if(!val.isString()){
        success = false;
        qWarning() << "Json value of \"" << key << "\" is not a string";
        return QString();
    }

    success = true;
    return val.toString();
}

bool MessageUtils::getBoolFromJsonObject(const QJsonObject &obj, const QString &key, bool &success)
{
    if(!obj.contains(key)){
        success = false;
        qWarning() << "Json object contains no key: "  << key;
        return false;
    }

    auto val = obj.value(key);
    if(!val.isBool()){
        success = false;
        qWarning() << "Json value of \"" << key << "\" is not bool";
        return false;
    }

    success = true;
    return val.toBool();
}

int MessageUtils::getIntFromJsonObject(const QJsonObject &obj, const QString &key, bool &success)
{
    if(!obj.contains(key)){
        success = false;
        qWarning() << "Json object contains no key: "  << key;
        return 0;
    }

    auto val = obj.value(key);
    if(!val.isDouble()){
        success = false;
        qWarning() << "Json value of \"" << key << "\" is not a number!";
        return 0;
    }

    success = true;
    return val.toInt();
}

MessageType MessageUtils::findResponseMesssageType(const MessageType messageType)
{
    static std::unordered_map<MessageType, MessageType> messageTypeToResponseType ={
        {MessageType::AddMessage, MessageType::AddMessageResponse},
        {MessageType::AddUser, MessageType::AddUserResponse},
        {MessageType::DeleteUser, MessageType::DeleteUserResponse},
        {MessageType::NewSessionRequest, MessageType::NewSessionResponse},
        {MessageType::GetChatMessages, MessageType::GetChatMessagesResponse},
        {MessageType::GetChatMessagesCount, MessageType::GetChatMessagesCountResponse},
        {MessageType::GetChatMessagesNearId, MessageType::GetChatMessagesNearIdResponse},
        {MessageType::ChangeUserPassword, MessageType::ChangeUserPasswordResponse}
    };

    if(messageTypeToResponseType.contains(messageType)){
        return messageTypeToResponseType[messageType];
    }
    else{
        return MessageType::Invalid;
    }
}
