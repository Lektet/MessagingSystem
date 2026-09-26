#ifndef GETCHATMESSAGESININTERVALMESSAGE_H
#define GETCHATMESSAGESININTERVALMESSAGE_H

#include <stdint.h>

#include "SessionMessage.h"

class GetChatMessagesNearIdMessage : public SessionMessage
{

public:
    explicit GetChatMessagesNearIdMessage(const QUuid& sessionId = QUuid(),
                                          const QString& messageId = "",
                                          const int numOfMessagesBefore = 0,
                                          const int numOfMessagesAfter = 0,
                                          bool includeMessageWithSpecId = false);

    QString getId() const;
    int getNumBefore() const;
    int getNumAfter() const;
    bool getIncludeMessage() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) const override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QString id;
    int numBefore;
    int numAfter;
    bool includeMessage;
};

#endif // GETCHATMESSAGESININTERVALMESSAGE_H
