#ifndef ADDMESSAGEMESSAGE_H
#define ADDMESSAGEMESSAGE_H

#include "SessionMessage.h"

#include "NewChatMessageData.h"

class AddChatMessageMessage : public SessionMessage
{
public:
    explicit AddChatMessageMessage(const QUuid& sessionId = QUuid(),
                      const NewChatMessageData& chatMessageData = NewChatMessageData());

    QString getMessageUsername() const;
    QString getMessageText() const;    
    NewChatMessageData getChatMessageData() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    NewChatMessageData messageData;
};

#endif // ADDMESSAGEMESSAGE_H
