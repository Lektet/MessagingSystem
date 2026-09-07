#include "SimpleMessage.h"

#include "MessageType.h"
#include "MessageUtils.h"

const QString TYPE_KEY = "Type";

SimpleMessage::SimpleMessage(MessageType type) :
    JsonSerializable(),
    messageType(type)
{
    int i = 0;
}

MessageType SimpleMessage::getMessageType() const
{
    return messageType;
}

void SimpleMessage::initRootObject(QJsonObject &rootObj) const
{
    rootObj.insert(TYPE_KEY, messageTypeToString(messageType));
}

bool SimpleMessage::initFromRootObject(const QJsonObject &rootObj)
{
    bool success = true;
    auto messageTypeString = MessageUtils::getStringFromJsonObject(rootObj, TYPE_KEY, success);
    if(!success){
        return false;
    }

    messageType = messageTypeFromString(messageTypeString);
    return true;
}
