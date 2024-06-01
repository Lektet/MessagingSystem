#include "SendMessageMessage.h"

#include "MessageType.h"

const QString MESSAGE_KEY = "Message";

SendMessageMessage::SendMessageMessage() :
    SimpleMessage(MessageType::SendMessage)
{

}

SendMessageMessage::SendMessageMessage(const QJsonObject &data) :
    SimpleMessage(MessageType::SendMessage),
    messageData(data)
{

}

QJsonObject SendMessageMessage::getMessageData() const
{
    return messageData;
}

void SendMessageMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    rootObj.insert(MESSAGE_KEY, messageData);
}

bool SendMessageMessage::initFromRootObject(const QJsonObject &rootObj)
{
    auto initSuccessful = SimpleMessage::initFromRootObject(rootObj);
    if(!initSuccessful){
        qDebug() << "Parent init failed";
        return false;
    }

    if(!rootObj.contains(MESSAGE_KEY)){
        qDebug() << "JSON root object contains no message";
        return false;
    }

    messageData = rootObj.value(MESSAGE_KEY).toObject();
    return true;
}
