#include "ChangeUserPasswordMessage.h"

#include "MessageUtils.h"

#include "MessageType.h"

const QString USERNAME_KEY = "Username";
const QString PASSWORD_KEY = "Password";

ChangeUserPasswordMessage::ChangeUserPasswordMessage(const QUuid &sessionId,
                                                     const QString &targetUsername,
                                                     const QString &newPassword):
    SessionMessage(sessionId, MessageType::ChangeUserPassword),
    username(targetUsername),
    password(newPassword)
{

}

QString ChangeUserPasswordMessage::getUsername() const
{
    return username;
}

QString ChangeUserPasswordMessage::getPassword() const
{
    return password;
}

void ChangeUserPasswordMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);

    rootObj.insert(USERNAME_KEY, username);
    rootObj.insert(PASSWORD_KEY, password);
}

bool ChangeUserPasswordMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
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
