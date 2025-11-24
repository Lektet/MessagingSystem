#include "NewSessionResponseMessage.h"

#include "MessageType.h"

const QString IS_VALID_KEY = "IsValid";

NewSessionResponseMessage::NewSessionResponseMessage(bool loginUsernameIsValid,
                                                     const QUuid &initialUserId,
                                                     const QUuid &sessionId) :
    SimpleMessage(MessageType::NewSessionResponse),
    NewSessionEstablishmentMessage(initialUserId, sessionId),
    usernameIsValid(loginUsernameIsValid)
{

}

bool NewSessionResponseMessage::getUsernameIsValid()
{
    return usernameIsValid;
}

void NewSessionResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    NewSessionEstablishmentMessage::initRootObject(rootObj);

    rootObj.insert(IS_VALID_KEY, usernameIsValid);
}

bool NewSessionResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SimpleMessage::initFromRootObject(rootObj) &&
          NewSessionEstablishmentMessage::initFromRootObject(rootObj))){
        qWarning() << "Parent init failed";
        return false;
    }

    if(!rootObj.contains(IS_VALID_KEY)){
        qWarning() << "Json object contains no log in result";
        return false;
    }

    auto isValidVal = rootObj.value(IS_VALID_KEY);
    if(!isValidVal.isBool()){
        qWarning() << "Log in result value is of wrong type";
        return false;
    }

    usernameIsValid = isValidVal.toBool();

    return true;
}
