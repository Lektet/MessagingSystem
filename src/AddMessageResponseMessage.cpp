#include "AddMessageResponseMessage.h"

#include "MessageType.h"

const QString RESULT = "RequestResult";

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
}

bool AddMessageResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }
    return true;
}
