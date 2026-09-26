#include "GetChatMessagesCountMessage.h"

#include "MessageType.h"

GetChatMessagesCountMessage::GetChatMessagesCountMessage(const QUuid &sessionId) :
    SessionMessage(sessionId, MessageType::GetChatMessagesCount)
{

}

void GetChatMessagesCountMessage::initRootObject(QJsonObject &rootObj) const
{
    SessionMessage::initRootObject(rootObj);
}

bool GetChatMessagesCountMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    return true;
}
