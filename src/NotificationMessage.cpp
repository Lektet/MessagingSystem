#include "NotificationMessage.h"

#include "MessageType.h"
#include "NotificationType.h"
#include "MessageUtils.h"

const QString NOTIFICATION_TYPE_KEY = "NotificationType";

NotificationMessage::NotificationMessage(const QUuid &sessionId, NotificationType type) :
    SessionMessage(sessionId, MessageType::Notification),
    notificationType(type)
{

}

void NotificationMessage::setNotificationType(NotificationType type)
{
    notificationType = type;
}

NotificationType NotificationMessage::getNotificationType() const
{
    return notificationType;
}

void NotificationMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    SessionMessage::initRootObject(rootObj);
    rootObj.insert(NOTIFICATION_TYPE_KEY, notificationTypeToString(notificationType));
}

bool NotificationMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SimpleMessage::initFromRootObject(rootObj) &&
          SessionMessage::initFromRootObject(rootObj))){
        qWarning() << "Parent init failed";
        return false;
    }

    bool success = true;
    auto notificationTypeString = MessageUtils::getStringFromJsonObject(rootObj, NOTIFICATION_TYPE_KEY, success);
    if(!success){
        return false;
    }

    notificationType = notificationTypeFromString(notificationTypeString);
    return true;
}
