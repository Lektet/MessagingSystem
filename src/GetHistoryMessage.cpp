#include "GetHistoryMessage.h"

#include "MessageType.h"

GetHistoryMessage::GetHistoryMessage(const QUuid &sessionId) :
    SessionMessage(sessionId, MessageType::GetHistory)
{

}

void GetHistoryMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);
}

bool GetHistoryMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    return true;
}
