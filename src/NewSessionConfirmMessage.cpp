#include "NewSessionConfirmMessage.h"

#include "MessageType.h"

NewSessionConfirmMessage::NewSessionConfirmMessage(const QUuid &initialUserId, const QUuid &sessionId) :
    NewSessionEstablishmentMessage(initialUserId,
                                     sessionId,
                                     MessageType::NewSessionConfirm),
    SessionMessage(sessionId, MessageType::NewSessionConfirm)
{

}

void NewSessionConfirmMessage::initRootObject(QJsonObject &rootObj) const
{
    NewSessionEstablishmentMessage::initRootObject(rootObj);
}

bool NewSessionConfirmMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!NewSessionEstablishmentMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    return true;
}
