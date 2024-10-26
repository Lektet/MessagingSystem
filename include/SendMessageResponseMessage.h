#ifndef SENDMESSAGERESPONSEMESSAGE_H
#define SENDMESSAGERESPONSEMESSAGE_H

#include "SimpleResponseMessage.h"

enum class Result;

class SendMessageResponseMessage : public SimpleMessage
{
public:
    SendMessageResponseMessage();
    SendMessageResponseMessage(Result result);

    Result getResult() const;
    void setResult(Result result);

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    Result sendMessageResult;
};

#endif // SENDMESSAGERESPONSEMESSAGE_H
