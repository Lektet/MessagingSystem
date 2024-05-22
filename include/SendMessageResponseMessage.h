#ifndef SENDMESSAGERESPONSEMESSAGE_H
#define SENDMESSAGERESPONSEMESSAGE_H

#include "SimpleMessage.h"

enum class Result;

class SendMessageResponseMessage : public SimpleMessage
{
public:
    SendMessageResponseMessage();

    void setResult(Result result);
    Result getResult() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    Result sendMessageResult;
};

#endif // SENDMESSAGERESPONSEMESSAGE_H
