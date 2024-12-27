#ifndef ADDMESSAGERESPONSEMESSAGE_H
#define ADDMESSAGERESPONSEMESSAGE_H

#include "SimpleResponseMessage.h"

enum class Result;

class AddMessageResponseMessage : public SimpleMessage
{
public:
    AddMessageResponseMessage();
    AddMessageResponseMessage(Result result);

    Result getResult() const;
    void setResult(Result result);

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    Result addMessageResult;
};

#endif // ADDMESSAGERESPONSEMESSAGE_H
