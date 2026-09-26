#ifndef GETHISTORYRESPONSEMESSAGE_H
#define GETHISTORYRESPONSEMESSAGE_H

#include "ResponseMessage.h"

#include <vector>

#include "ChatMessageData.h"

class GetChatMessagesResponseMessage : public ResponseMessage
{
public:
    explicit GetChatMessagesResponseMessage(const QUuid& sessionId = QUuid(),
                                            std::vector<ChatMessageData> messagesHistory = std::vector<ChatMessageData>(),
                                            const MessageType messageType = MessageType::GetChatMessagesResponse,
                                            const ErrorInfo messageErrorInfo = {ErrorCode::NoError, ""});
    
    std::vector<ChatMessageData> getMessagesHistory() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) const override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    std::vector<ChatMessageData> messages;
};

#endif // GETHISTORYRESPONSEMESSAGE_H
