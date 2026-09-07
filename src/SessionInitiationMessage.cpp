#include "SessionInitiationMessage.h"

#include "MessageType.h"
#include "MessageUtils.h"

const QString USER_ID_KEY = "UserId";

SessionInitiationMessage::SessionInitiationMessage(const QUuid& initialUserId) :
    userId(initialUserId)
{

}

QUuid SessionInitiationMessage::getUserId()
{
    return userId;
}

void SessionInitiationMessage::initRootObject(QJsonObject &rootObj) const
{
    rootObj.insert(USER_ID_KEY, userId.toString());
}

bool SessionInitiationMessage::initFromRootObject(const QJsonObject &rootObj)
{
    bool success = true;
    auto userIdString = MessageUtils::getStringFromJsonObject(rootObj, USER_ID_KEY, success);
    if(!success){
        return false;
    }
    userId = QUuid(userIdString);

    return true;
}
