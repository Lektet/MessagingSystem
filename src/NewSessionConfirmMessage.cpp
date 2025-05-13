#include "NewSessionConfirmMessage.h"

#include "MessageType.h"

NewSessionConfirmMessage::NewSessionConfirmMessage(const QUuid &initialUserId, const QUuid &sessionId) :
    SimpleMessage(MessageType::NewSessionConfirm),
    NewSessionEstablishmentMessage(initialUserId, sessionId)
{

}

void NewSessionConfirmMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    NewSessionEstablishmentMessage::initRootObject(rootObj);
}

bool NewSessionConfirmMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SimpleMessage::initFromRootObject(rootObj) &&
          NewSessionEstablishmentMessage::initFromRootObject(rootObj))){
        qWarning() << "Parent init failed";
        return false;
    }

    return true;
}
