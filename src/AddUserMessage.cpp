#include "AddUserMessage.h"

#include "MessageUtils.h"

#include "MessageType.h"

const QString USERNAME_KEY = "Username";
const QString PASSWORD_KEY = "Password";
const QString ROLE_KEY = "Role";

AddUserMessage::AddUserMessage(const QUuid &sessionId,
                                const QString &newUsername,
                                const QString &newPassword,
                                const UserRole newUserRole) :
    SessionMessage(sessionId, MessageType::AddUser),
    username(newUsername),
    password(newPassword),
    role(newUserRole)
{

}

QString AddUserMessage::getUsername() const
{
    return username;
}

QString AddUserMessage::getPassword() const
{
    return password;
}

UserRole AddUserMessage::getRole() const
{
    return role;
}

void AddUserMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);

    rootObj.insert(USERNAME_KEY, username);
    rootObj.insert(PASSWORD_KEY, password);
    rootObj.insert(ROLE_KEY, (int)role);
}

bool AddUserMessage::initFromRootObject(const QJsonObject &rootObj)
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

    role = UserRole(MessageUtils::getIntFromJsonObject(rootObj, ROLE_KEY, success));
    if(!success){
        return false;
    }

    return true;
}
