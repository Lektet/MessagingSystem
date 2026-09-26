#include "GetChatMessagesNearIdMessage.h"

#include "MessageUtils.h"

const QString ID_KEY = "Id";
const QString NUM_BEFORE_KEY = "NumBefor";
const QString NUM_AFTER_KEY = "NumAfter";
const QString INCLUDE_MESSAGE_KEY = "IncludeMessage";

GetChatMessagesNearIdMessage::GetChatMessagesNearIdMessage(const QUuid& sessionId,
                                                           const QString& messageId,
                                                           const int numOfMessagesBefore,
                                                           const int numOfMessagesAfter,
                                                           bool includeMessageWithSpecId) :
    SessionMessage(sessionId, MessageType::GetChatMessagesNearId),
    id(messageId),
    numBefore(numOfMessagesBefore),
    numAfter(numOfMessagesAfter),
    includeMessage(includeMessageWithSpecId)
{

}

QString GetChatMessagesNearIdMessage::getId() const
{
    return id;
}

int GetChatMessagesNearIdMessage::getNumBefore() const
{
    return numBefore;
}

int GetChatMessagesNearIdMessage::getNumAfter() const
{
    return numAfter;
}

bool GetChatMessagesNearIdMessage::getIncludeMessage() const
{
    return includeMessage;
}

void GetChatMessagesNearIdMessage::initRootObject(QJsonObject &rootObj) const
{
    SessionMessage::initRootObject(rootObj);

    rootObj.insert(ID_KEY, id);
    rootObj.insert(NUM_BEFORE_KEY, numBefore);
    rootObj.insert(NUM_AFTER_KEY, numAfter);
    rootObj.insert(INCLUDE_MESSAGE_KEY, includeMessage);
}

bool GetChatMessagesNearIdMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    bool success = true;
    id = MessageUtils::getStringFromJsonObject(rootObj, NUM_BEFORE_KEY, success);
    if(!success){
        return false;
    }

    numBefore = MessageUtils::getIntFromJsonObject(rootObj, NUM_BEFORE_KEY, success);
    if(!success){
        return false;
    }

    numAfter = MessageUtils::getIntFromJsonObject(rootObj, NUM_AFTER_KEY, success);
    if(!success){
        return false;
    }

    includeMessage = MessageUtils::getBoolFromJsonObject(rootObj, INCLUDE_MESSAGE_KEY, success);
    if(!success){
        return false;
    }

    return true;
}
