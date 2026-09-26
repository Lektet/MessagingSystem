#ifndef GETCHATMESSAGESCOUNTMESSAGE_H
#define GETCHATMESSAGESCOUNTMESSAGE_H

#include "SessionMessage.h"

enum class MessageType;

class GetChatMessagesCountMessage : public SessionMessage
{

public:
    explicit GetChatMessagesCountMessage(const QUuid& sessionId = QUuid());

protected:
    virtual void initRootObject(QJsonObject &rootObj) const override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;
};

#endif // GETCHATMESSAGESCOUNTMESSAGE_H
