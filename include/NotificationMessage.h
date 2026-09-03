#ifndef NOTIFICATIONMESSAGE_H
#define NOTIFICATIONMESSAGE_H

#include "SessionMessage.h"

#include "NotificationType.h"

class NotificationMessage : public SessionMessage
{    
public:
    explicit NotificationMessage(const QUuid& sessionId = QUuid(),
                        NotificationType type = NotificationType::Invalid);

    void setNotificationType(NotificationType type);
    NotificationType getNotificationType() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    NotificationType notificationType;
};

#endif // NOTIFICATIONMESSAGE_H
