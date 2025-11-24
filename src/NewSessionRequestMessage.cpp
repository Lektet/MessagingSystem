#include "NewSessionRequestMessage.h"

#include "MessageType.h"
#include "MessageUtils.h"

const QString USERNAME_KEY = "Username";

NewSessionRequestMessage::NewSessionRequestMessage(const QUuid &initialUserId, const QString &authUsername) :
    SimpleMessage(MessageType::NewSessionRequest),
    SessionInitiationMessage(initialUserId),
    username(authUsername)
{

}

QString NewSessionRequestMessage::getUsername() const
{
    return username;
}

void NewSessionRequestMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    SessionInitiationMessage::initRootObject(rootObj);

    rootObj.insert(USERNAME_KEY, username);
}

bool NewSessionRequestMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SimpleMessage::initFromRootObject(rootObj) &&
          SessionInitiationMessage::initFromRootObject(rootObj))){
        qWarning() << "Parent init failed";
        return false;
    }

    username = MessageUtils::getStringFromJsonObject(rootObj, USERNAME_KEY);
    if(username.isNull()){
        return false;
    }
    return true;
}
