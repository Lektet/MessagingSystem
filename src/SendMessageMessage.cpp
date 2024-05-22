#include "SendMessageMessage.h"

#include "MessageType.h"

const QString MESSAGE_KEY = "Message";

SendMessageMessage::SendMessageMessage() :
    SimpleMessage(MessageType::SendMessage)
{

}

void SendMessageMessage::setMessageData(const QString &data)
{
    messageData = data;
}

QString SendMessageMessage::getMessageData() const
{
    return messageData;
}

void SendMessageMessage::initRootObject(QJsonObject &rootObj)
{
    rootObj.insert(MESSAGE_KEY, messageData);
}

bool SendMessageMessage::initFromRootObject(const QJsonObject &rootObj)
{
    auto initSuccessful = SimpleMessage::initFromRootObject(rootObj);
    if(!initSuccessful){
        return false;
    }

    if(!rootObj.contains(MESSAGE_KEY)){
        qDebug() << "JSON root object contains no message";
        return false;
    }

    messageData = rootObj.value(MESSAGE_KEY).toString();
    return true;
}
