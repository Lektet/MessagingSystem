#ifndef SENDMESSAGEMESSAGE_H
#define SENDMESSAGEMESSAGE_H

#include "SimpleMessage.h"

class SendMessageMessage : public SimpleMessage
{
public:
    SendMessageMessage();

    void setMessageData(const QString& data);
    QString getMessageData() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QString messageData;
};

#endif // SENDMESSAGEMESSAGE_H
