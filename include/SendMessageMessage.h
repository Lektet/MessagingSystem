#ifndef SENDMESSAGEMESSAGE_H
#define SENDMESSAGEMESSAGE_H

#include "SimpleMessage.h"

class SendMessageMessage : public SimpleMessage
{
public:
    SendMessageMessage();
    SendMessageMessage(const QJsonObject& data);

    QJsonObject getMessageData() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QJsonObject messageData;
};

#endif // SENDMESSAGEMESSAGE_H
