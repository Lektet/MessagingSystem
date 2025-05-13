#include "NewSessionResponseMessage.h"

#include "MessageType.h"

const QString IS_VALID_KEY = "IsValid";

NewSessionResponseMessage::NewSessionResponseMessage(bool usernameIsValid,
                                                     const QUuid &initialUserId,
                                                     const QUuid &sessionId) :
    SimpleMessage(MessageType::NewSessionResponse),
    NewSessionEstablishmentMessage(initialUserId, sessionId),
    isValid(usernameIsValid)
{

}

bool NewSessionResponseMessage::getUsernameIsValid()
{
    return isValid;
}

void NewSessionResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    NewSessionEstablishmentMessage::initRootObject(rootObj);

    rootObj.insert(IS_VALID_KEY, isValid);
}

bool NewSessionResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SimpleMessage::initFromRootObject(rootObj) &&
          NewSessionEstablishmentMessage::initFromRootObject(rootObj))){
        qWarning() << "Parent init failed";
        return false;
    }

    isValid = rootObj.value(IS_VALID_KEY).toBool();

    return true;
}
