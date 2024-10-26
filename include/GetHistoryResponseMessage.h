#ifndef GETHISTORYRESPONSEMESSAGE_H
#define GETHISTORYRESPONSEMESSAGE_H

#include "SimpleMessage.h"

#include <vector>

#include "ChatMessageData.h"

class GetHistoryResponseMessage : public SimpleMessage
{
public:
    GetHistoryResponseMessage();
    GetHistoryResponseMessage(std::vector<ChatMessageData> messagesHistory);

    std::vector<ChatMessageData> getMessagesHistory() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    std::vector<ChatMessageData> messages;
};

#endif // GETHISTORYRESPONSEMESSAGE_H
