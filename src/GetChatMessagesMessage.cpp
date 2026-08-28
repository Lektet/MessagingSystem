#include "GetChatMessagesMessage.h"

#include "MessageType.h"

GetChatMessagesMessage::GetChatMessagesMessage(const QUuid &sessionId) :
    SessionMessage(sessionId, MessageType::GetChatMessages)
{

}

void GetChatMessagesMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);
}

bool GetChatMessagesMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    return true;
}
