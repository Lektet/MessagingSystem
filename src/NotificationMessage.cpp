#include "NotificationMessage.h"

#include "MessageType.h"
#include "NotificationType.h"

const QString NOTIFICATION_TYPE_KEY = "NotificationType";

NotificationMessage::NotificationMessage() :
    SimpleMessage(MessageType::Notification),
    notificationType(NotificationType::Invalid)
{

}

NotificationMessage::NotificationMessage(NotificationType type) :
    SimpleMessage(MessageType::Notification),
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
    rootObj.insert(NOTIFICATION_TYPE_KEY, notificationTypeToString(notificationType));
}

bool NotificationMessage::initFromRootObject(const QJsonObject &rootObj)
{
    auto initSuccessful = SimpleMessage::initFromRootObject(rootObj);
    if(!initSuccessful){
        qWarning() << "Parent init failed";
        return false;
    }

    if(!rootObj.contains(NOTIFICATION_TYPE_KEY)){
        qWarning() << "JSON root object contains no type";
        return false;
    }

    notificationType = notificationTypeFromString(rootObj.value(NOTIFICATION_TYPE_KEY).toString());
    return true;
}
