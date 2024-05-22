#ifndef NOTIFICATIONTYPE_H
#define NOTIFICATIONTYPE_H

#include "QString"

enum class NotificationType{
    Invalid,
    MessagesUpdated
};

QString notificationTypeToString(const NotificationType val);
NotificationType notificationTypeFromString(const QString &notificationType);

#endif // NOTIFICATIONTYPE_H
