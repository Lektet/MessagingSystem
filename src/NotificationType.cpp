#include "NotificationType.h"

#include <map>

#include "utils.h"

std::map<NotificationType, QString> notificationTypeStrings = {
    {NotificationType::Invalid, "Invalid"},
    {NotificationType::MessagesUpdated, "MessagesUpdated"}
};

QString notificationTypeToString(const NotificationType val)
{
    return notificationTypeStrings.at(val);
}



NotificationType notificationTypeFromString(const QString &notificationType)
{
    return searchMapByValue(notificationTypeStrings, notificationType, NotificationType::Invalid);
}
