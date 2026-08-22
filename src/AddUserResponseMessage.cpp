#include "AddUserResponseMessage.h"

#include "MessageType.h"

#include "MessageUtils.h"

const QString RESULT_KEY = "RequestResult";

AddUserResponseMessage::AddUserResponseMessage(const QUuid &sessionId, bool addMessageResult):
    SessionMessage(sessionId, MessageType::AddUserResponse),
    result(addMessageResult)
{

}

bool AddUserResponseMessage::getResult() const
{
    return result;
}

void AddUserResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);

    rootObj.insert(RESULT_KEY, result);
}

bool AddUserResponseMessage::initFromRootObject(const QJsonObject &rootObj)
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
