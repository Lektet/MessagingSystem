#include "SessionMessage.h"

#include "MessageUtils.h"
#include "MessageType.h"


const QString SESSION_ID_KEY = "SessionId";

SessionMessage::SessionMessage(const QUuid &messageSessionId,
                               MessageType messageType) :
    SimpleMessage(messageType),
    sessionId(messageSessionId)
{
    int i = 0;
}

QUuid SessionMessage::getSessionId() const
{
    return sessionId;
}

void SessionMessage::initRootObject(QJsonObject &rootObj) const
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

    bool success = true;
    auto sessionIdString = MessageUtils::getStringFromJsonObject(rootObj, SESSION_ID_KEY, success);
    if(!success){
        return false;
    }
    sessionId = QUuid(sessionIdString);

    return true;
}
