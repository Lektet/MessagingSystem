#include "GetChatMessagesCountResponseMessage.h"

#include "MessageUtils.h"

const QString COUNT_KEY = "Count";

GetChatMessagesCountResponseMessage::GetChatMessagesCountResponseMessage(
    const QUuid &sessionId,
    const int messageCount,
    const ErrorInfo messageErrorInfo) :
    ResponseMessage(sessionId, MessageType::GetChatMessagesCountResponse, messageErrorInfo)
{

}

int GetChatMessagesCountResponseMessage::getCount() const
{
    return count;
}

void GetChatMessagesCountResponseMessage::initRootObject(QJsonObject &rootObj) const
{
    ResponseMessage::initRootObject(rootObj);

    rootObj.insert(COUNT_KEY, count);
}

bool GetChatMessagesCountResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!ResponseMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    bool success = true;
    count = MessageUtils::getIntFromJsonObject(rootObj, COUNT_KEY, success);
    if(!success){
        return false;
    }

    return true;
}
