#include "NewSessionResponseMessage.h"

#include "MessageType.h"

#include "MessageUtils.h"

const QString USER_ROLE_KEY = "UserRole";

NewSessionResponseMessage::NewSessionResponseMessage(
    const QUuid &initialUserId,
    const QUuid &sessionId,
    const UserRole role,
    const ErrorInfo& messageErrorInfo) :
    SessionMessage(sessionId, MessageType::NewSessionResponse),
    NewSessionEstablishmentMessage(initialUserId,
                                     sessionId,
                                     MessageType::NewSessionResponse),
    ResponseMessage(sessionId,
                      MessageType::NewSessionResponse,
                      messageErrorInfo),
    userRole(role)
{

}

UserRole NewSessionResponseMessage::getUserRole()
{
    return userRole;
}

void NewSessionResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);
    NewSessionEstablishmentMessage::initRootObject(rootObj);
    ResponseMessage::initRootObject(rootObj);

    rootObj.insert(USER_ROLE_KEY, userRoleToString(userRole));
}

bool NewSessionResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    if(!NewSessionEstablishmentMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    if(!ResponseMessage::initFromRootObject(rootObj)){
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
