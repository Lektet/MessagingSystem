#include "AddMessageResponseMessage.h"

#include "MessageType.h"

#include "MessageUtils.h"

const QString RESULT_KEY = "RequestResult";

AddMessageResponseMessage::AddMessageResponseMessage(const QUuid &sessionId, bool addMessageResult):
    SessionMessage(sessionId, MessageType::AddMessageResponse),
    result(addMessageResult)
{

}

bool AddMessageResponseMessage::getResult() const
{
    return result;
}

void AddMessageResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);

    rootObj.insert(RESULT_KEY, result);
}

bool AddMessageResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    bool success = true;
    result = MessageUtils::getBoolFromJsonObject(rootObj, RESULT_KEY, success);
    if(!success){
        return false;
    }

    return true;
}
