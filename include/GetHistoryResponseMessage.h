#ifndef GETHISTORYRESPONSEMESSAGE_H
#define GETHISTORYRESPONSEMESSAGE_H

#include "SimpleMessage.h"

enum class MessageType;

class GetHistoryResponseMessage : public SimpleMessage
{
public:
    GetHistoryResponseMessage();

    void setMessages(const QString& messages);
    QString getMessagesHistory() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QString messagesHistory;
};

#endif // GETHISTORYRESPONSEMESSAGE_H
