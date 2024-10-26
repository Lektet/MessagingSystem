#include "SendMessageMessage.h"

#include "MessageType.h"

const QString MESSAGE_OBJECT_KEY = "MessageObject";
const QString MESSAGE_USERNAME_KEY = "Username";
const QString MESSAGE_TEXT_KEY = "Text";

SendMessageMessage::SendMessageMessage(const NewChatMessageData& chatMessageData) :
    SimpleMessage(MessageType::SendMessage),
    messageData(chatMessageData)
{

}

QString SendMessageMessage::getMessageUsername() const
{
    return messageData.username;
}

QString SendMessageMessage::getMessageText() const
{
    return messageData.text;
}

NewChatMessageData SendMessageMessage::getChatMessageData() const
{
    return messageData;
}

void SendMessageMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);

    QJsonObject messageObject;
    messageObject.insert(MESSAGE_USERNAME_KEY, messageData.username);
    messageObject.insert(MESSAGE_TEXT_KEY, messageData.text);

    rootObj.insert(MESSAGE_OBJECT_KEY, messageObject);

}

bool SendMessageMessage::initFromRootObject(const QJsonObject &rootObj)
{
    auto initSuccessful = SimpleMessage::initFromRootObject(rootObj);
    if(!initSuccessful){
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
