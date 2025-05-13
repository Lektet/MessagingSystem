#include "AddMessageMessage.h"

#include "MessageType.h"

const QString MESSAGE_OBJECT_KEY = "MessageObject";
const QString MESSAGE_USERNAME_KEY = "Username";
const QString MESSAGE_TEXT_KEY = "Text";

AddMessageMessage::AddMessageMessage(const QUuid &sessionId, const NewChatMessageData& chatMessageData) :
    SimpleMessage(MessageType::AddMessage),
    SessionMessage(sessionId),
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
    SimpleMessage::initRootObject(rootObj);
    SessionMessage::initRootObject(rootObj);

    QJsonObject messageObject;
    messageObject.insert(MESSAGE_USERNAME_KEY, messageData.username);
    messageObject.insert(MESSAGE_TEXT_KEY, messageData.text);

    rootObj.insert(MESSAGE_OBJECT_KEY, messageObject);
}

bool AddMessageMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SimpleMessage::initFromRootObject(rootObj) &&
          SessionMessage::initFromRootObject(rootObj))){
        qWarning() << "Parent init failed";
        return false;
    }

    if(!rootObj.contains(MESSAGE_OBJECT_KEY)){
        qWarning() << "JSON root object contains no message";
        return false;
    }
    auto messageObject = rootObj.value(MESSAGE_OBJECT_KEY).toObject();

    if(!messageObject.contains(MESSAGE_USERNAME_KEY)){
        qWarning() << "JSON root object contains no username";
        return false;
    }
    messageData.username = messageObject.value(MESSAGE_USERNAME_KEY).toString();

    if(!messageObject.contains(MESSAGE_TEXT_KEY)){
        qWarning() << "JSON root object contains no message text";
        return false;
    }
    messageData.text = messageObject.value(MESSAGE_TEXT_KEY).toString();

    return true;
}
