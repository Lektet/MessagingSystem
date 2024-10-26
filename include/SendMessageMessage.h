#ifndef SENDMESSAGEMESSAGE_H
#define SENDMESSAGEMESSAGE_H

#include "SimpleMessage.h"

#include "NewChatMessageData.h"

class SendMessageMessage : public SimpleMessage
{
public:
    SendMessageMessage(const NewChatMessageData& chatMessageData = NewChatMessageData());

    QString getMessageUsername() const;
    QString getMessageText() const;    
    NewChatMessageData getChatMessageData() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    NewChatMessageData messageData;
};

#endif // SENDMESSAGEMESSAGE_H
