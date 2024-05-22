#ifndef NOTIFICATIONMESSAGE_H
#define NOTIFICATIONMESSAGE_H

#include "SimpleMessage.h"

enum class NotificationType;

class NotificationMessage : public SimpleMessage
{
    NotificationMessage();

public:
    void setNotificationType(NotificationType type);
    NotificationType getNotificationType() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    NotificationType notificationType;
};

#endif // NOTIFICATIONMESSAGE_H
