#include "DeleteUserMessage.h"

#include "MessageUtils.h"

const QString USERNAME_KEY = "UserToDelete";

DeleteUserMessage::DeleteUserMessage(const QUuid &sessionId, const QString &userToDelete):
    SessionMessage(sessionId, MessageType::DeleteUser),
    username(userToDelete)
{

}

QString DeleteUserMessage::getUsername() const
{
    return username;
}

void DeleteUserMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);

    rootObj.insert(USERNAME_KEY, username);
}

bool DeleteUserMessage::initFromRootObject(const QJsonObject &rootObj)
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

    return true;
}
