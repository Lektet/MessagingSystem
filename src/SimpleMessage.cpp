#include "SimpleMessage.h"

#include "MessageType.h"

const QString TYPE_KEY = "Type";

SimpleMessage::SimpleMessage(MessageType type) :
    messageType(type)
{

}

MessageType SimpleMessage::getMessageType() const
{
    return messageType;
}

void SimpleMessage::initRootObject(QJsonObject &rootObj)
{
    rootObj.insert(TYPE_KEY, messageTypeToString(messageType));
}

bool SimpleMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!rootObj.contains(TYPE_KEY)){
        qDebug() << "JSON root object contains no type";
        return false;
    }

    messageType = messageTypeFromString(rootObj.value(TYPE_KEY).toString());
    return true;
}
