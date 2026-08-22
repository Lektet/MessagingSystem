#include "NewSessionRequestMessage.h"

#include "MessageType.h"
#include "MessageUtils.h"

const QString USERNAME_KEY = "Username";
const QString PASSWORD_KEY = "Password";

NewSessionRequestMessage::NewSessionRequestMessage(const QUuid &initialUserId,
                                                   const QString &authUsername,
                                                   const QString& authPassword) :
    SimpleMessage(MessageType::NewSessionRequest),
    SessionInitiationMessage(initialUserId),
    username(authUsername),
    password(authPassword)
{

}

QString NewSessionRequestMessage::getUsername() const
{
    return username;
}

QString NewSessionRequestMessage::getPassword() const
{
    return password;
}

void NewSessionRequestMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    SessionInitiationMessage::initRootObject(rootObj);

    rootObj.insert(USERNAME_KEY, username);
    rootObj.insert(PASSWORD_KEY, password);
}

bool NewSessionRequestMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SimpleMessage::initFromRootObject(rootObj) &&
          SessionInitiationMessage::initFromRootObject(rootObj))){
        qWarning() << "Parent init failed";
        return false;
    }

    bool success = true;
    username = MessageUtils::getStringFromJsonObject(rootObj, USERNAME_KEY, success);
    if(!success){
        return false;
    }

    password = MessageUtils::getStringFromJsonObject(rootObj, PASSWORD_KEY, success);
    if(!success){
        return false;
    }

    return true;
}
