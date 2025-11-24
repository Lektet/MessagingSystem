#include "SessionMessage.h"

#include "MessageUtils.h"
#include "MessageType.h"


const QString SESSION_ID_KEY = "SessionId";

SessionMessage::SessionMessage(const QUuid &messageSessionId) :
    SimpleMessage(MessageType::Invalid),
    sessionId(messageSessionId)
{

}

QUuid SessionMessage::getSessionId() const
{
    return sessionId;
}

void SessionMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    rootObj.insert(SESSION_ID_KEY, sessionId.toString());
}

bool SessionMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SimpleMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    auto sessionIdString = MessageUtils::getStringFromJsonObject(rootObj, SESSION_ID_KEY);
    if(sessionIdString.isNull()){
        return false;
    }

    sessionId = QUuid(sessionIdString);
    return true;
}
