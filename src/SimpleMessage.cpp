#include "SimpleMessage.h"

#include "MessageType.h"
#include "MessageUtils.h"

const QString TYPE_KEY = "Type";

SimpleMessage::SimpleMessage(MessageType type) :
    JsonSerializable(),
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
    auto messageTypeString = MessageUtils::getStringFromJsonObject(rootObj, TYPE_KEY);
    if(messageTypeString.isNull()){
        return false;
    }

    messageType = messageTypeFromString(messageTypeString);
    return true;
}
