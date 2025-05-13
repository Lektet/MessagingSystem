#include "SessionMessage.h"

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
    rootObj.insert(SESSION_ID_KEY, sessionId.toString());

}

bool SessionMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!rootObj.contains(SESSION_ID_KEY)){
        qWarning() << "JSON root object contains no session id";
        return false;
    }

    sessionId = QUuid(rootObj.value(SESSION_ID_KEY).toString());
    return true;
}
