#include "NewSessionEstablishmentMessage.h"

NewSessionEstablishmentMessage::NewSessionEstablishmentMessage
    (const QUuid &initialUserId, const QUuid &sessionId, const MessageType messageType):
    SessionInitiationMessage(initialUserId),
    SessionMessage(sessionId, messageType)

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
