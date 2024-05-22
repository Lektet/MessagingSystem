#include "NotificationMessage.h"

#include "NotificationType.h"

const QString NOTIFICATION_TYPE_KEY = "NotificationType";

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
    rootObj.insert(NOTIFICATION_TYPE_KEY, notificationTypeToString(notificationType));
}

bool NotificationMessage::initFromRootObject(const QJsonObject &rootObj)
{
    auto initSuccessful = SimpleMessage::initFromRootObject(rootObj);
    if(!initSuccessful){
        return false;
    }

    if(!rootObj.contains(NOTIFICATION_TYPE_KEY)){
        qDebug() << "JSON root object contains no type";
        return false;
    }

    notificationType = notificationTypeFromString(rootObj.value(NOTIFICATION_TYPE_KEY).toString());
    return true;
}
