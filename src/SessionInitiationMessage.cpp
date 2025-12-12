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

void SessionInitiationMessage::initRootObject(QJsonObject &rootObj)
{
    rootObj.insert(USER_ID_KEY, userId.toString());
}

bool SessionInitiationMessage::initFromRootObject(const QJsonObject &rootObj)
{
    auto userIdString = MessageUtils::getStringFromJsonObject(rootObj, USER_ID_KEY);
    if(userIdString.isNull()){
        return false;
    }

    userId = QUuid(userIdString);
    return true;
}
