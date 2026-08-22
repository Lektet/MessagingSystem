#include "AddMessageMessage.h"

#include "MessageType.h"
#include "MessageUtils.h"

const QString MESSAGE_OBJECT_KEY = "MessageObject";
const QString MESSAGE_USERNAME_KEY = "Username";
const QString MESSAGE_TEXT_KEY = "Text";

AddMessageMessage::AddMessageMessage(const QUuid &sessionId, const NewChatMessageData& chatMessageData) :
    SessionMessage(sessionId, MessageType::AddMessage),
    messageData(chatMessageData)
{

}

QString AddMessageMessage::getMessageUsername() const
{
    return messageData.username;
}

QString AddMessageMessage::getMessageText() const
{
    return messageData.text;
}

NewChatMessageData AddMessageMessage::getChatMessageData() const
{
    return messageData;
}

void AddMessageMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);

    QJsonObject messageObject;
    messageObject.insert(MESSAGE_USERNAME_KEY, messageData.username);
    messageObject.insert(MESSAGE_TEXT_KEY, messageData.text);

    rootObj.insert(MESSAGE_OBJECT_KEY, messageObject);
}

bool AddMessageMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    if(!rootObj.contains(MESSAGE_OBJECT_KEY)){
        qWarning() << "JSON root object contains no message";
        return false;
    }
    auto messageObject = rootObj.value(MESSAGE_OBJECT_KEY).toObject();

    bool success = true;
    auto username  = MessageUtils::getStringFromJsonObject(messageObject, MESSAGE_USERNAME_KEY, success);
    if(!success){
        return false;
    }
    messageData.username = std::move(username);

    auto text  = MessageUtils::getStringFromJsonObject(messageObject, MESSAGE_TEXT_KEY, success);
    if(!success){
        return false;
    }
    messageData.text = std::move(text);

    return true;
}
