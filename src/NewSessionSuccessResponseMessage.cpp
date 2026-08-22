#include "NewSessionSuccessResponseMessage.h"

#include "MessageType.h"

#include "MessageUtils.h"

const QString USER_ROLE_KEY = "UserRole";

NewSessionSuccessResponseMessage::NewSessionSuccessResponseMessage(
    const QUuid &initialUserId,
    const QUuid &sessionId,
    const UserRole role) :
    NewSessionEstablishmentMessage(initialUserId,
                                     sessionId,
                                     MessageType::NewSessionResponse),
    userRole(role)
{

}

UserRole NewSessionSuccessResponseMessage::getUserRole()
{
    return userRole;
}

void NewSessionSuccessResponseMessage::initRootObject(QJsonObject &rootObj)
{
    NewSessionEstablishmentMessage::initRootObject(rootObj);

    rootObj.insert(USER_ROLE_KEY, userRoleToString(userRole));
}

bool NewSessionSuccessResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!NewSessionEstablishmentMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    bool success = true;
    auto userRoleString = MessageUtils::getStringFromJsonObject(rootObj, USER_ROLE_KEY, success);
    if(!success){
        return false;
    }
    userRole = userRoleFromString(userRoleString);

    return true;
}
