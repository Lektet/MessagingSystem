#ifndef GETHISTORYRESPONSEMESSAGE_H
#define GETHISTORYRESPONSEMESSAGE_H

#include "SessionMessage.h"
#include "ResponseMessage.h"

#include <vector>

#include "ChatMessageData.h"

class GetHistoryResponseMessage : public ResponseMessage
{
public:
    GetHistoryResponseMessage(const QUuid& sessionId = QUuid(),
                              std::vector<ChatMessageData> messagesHistory = std::vector<ChatMessageData>(),
                              const ErrorInfo messageErrorInfo = {ErrorCode::Undefined, ""});

    std::vector<ChatMessageData> getMessagesHistory() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    std::vector<ChatMessageData> messages;
};

#endif // GETHISTORYRESPONSEMESSAGE_H
