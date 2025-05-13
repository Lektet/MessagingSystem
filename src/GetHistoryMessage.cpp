#include "GetHistoryMessage.h"

#include "MessageType.h"

GetHistoryMessage::GetHistoryMessage(const QUuid &sessionId) :
    SimpleMessage(MessageType::GetHistory),
    SessionMessage(sessionId)
{

}

void GetHistoryMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    SessionMessage::initRootObject(rootObj);
}

bool GetHistoryMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SimpleMessage::initFromRootObject(rootObj) &&
          SessionMessage::initFromRootObject(rootObj))){
        qWarning() << "Parent init failed";
        return false;
    }

    return true;
}
