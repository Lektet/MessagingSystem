#include "NewSessionEstablishmentMessage.h"

#include "MessageType.h"

NewSessionEstablishmentMessage::NewSessionEstablishmentMessage
    (const QUuid &initialUserId, const QUuid &sessionId):
    SimpleMessage(MessageType::Invalid),
    SessionInitiationMessage(initialUserId),
    SessionMessage(sessionId)

{

}

void NewSessionEstablishmentMessage::initRootObject(QJsonObject &rootObj)
{
    SessionInitiationMessage::initRootObject(rootObj);
    SessionMessage::initRootObject(rootObj);
}

bool NewSessionEstablishmentMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SessionInitiationMessage::initFromRootObject(rootObj) &&
          SessionMessage::initFromRootObject(rootObj))){
        qWarning() << "Parent init failed";
        return false;
    }

    return true;
}
