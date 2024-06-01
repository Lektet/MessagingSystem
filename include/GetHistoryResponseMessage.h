#ifndef GETHISTORYRESPONSEMESSAGE_H
#define GETHISTORYRESPONSEMESSAGE_H

#include "SimpleMessage.h"

#include "QJsonArray"

enum class MessageType;

class GetHistoryResponseMessage : public SimpleMessage
{
public:
    GetHistoryResponseMessage();
    GetHistoryResponseMessage(const QJsonArray& messages);

    QJsonArray getMessagesHistory() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QJsonArray messagesHistory;
};

#endif // GETHISTORYRESPONSEMESSAGE_H
