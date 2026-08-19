#include "NewSessionFailedResponseMessage.h"

#include "MessageType.h"

NewSessionFailedResponseMessage::NewSessionFailedResponseMessage(const QUuid &initialUserId):
    SimpleMessage(MessageType::NewSessionFailedResponse),
    SessionInitiationMessage(initialUserId)
{

}

void NewSessionFailedResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    SessionInitiationMessage::initRootObject(rootObj);
}

bool NewSessionFailedResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SimpleMessage::initFromRootObject(rootObj) ||
        !SessionInitiationMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    return true;
}
