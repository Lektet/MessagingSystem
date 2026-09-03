#ifndef GETCHATMESSAGESMESSAGE_H
#define GETCHATMESSAGESMESSAGE_H

#include "SessionMessage.h"

enum class MessageType;

class GetChatMessagesMessage : public SessionMessage
{

public:
    explicit GetChatMessagesMessage(const QUuid& sessionId = QUuid());

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;
};

#endif // GETCHATMESSAGESMESSAGE_H
