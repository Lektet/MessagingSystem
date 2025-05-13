#include "SessionInitiationMessage.h"

#include "MessageType.h"

const QString USER_ID_KEY = "UserId";

SessionInitiationMessage::SessionInitiationMessage(const QUuid& initialUserId) :
    SimpleMessage(MessageType::Invalid),
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
    if(!rootObj.contains(USER_ID_KEY)){
        qWarning() << "JSON root object contains no type";
        return false;
    }

    userId = QUuid(rootObj.value(USER_ID_KEY).toString());
    return true;
}
