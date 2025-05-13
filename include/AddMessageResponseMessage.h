#ifndef ADDMESSAGERESPONSEMESSAGE_H
#define ADDMESSAGERESPONSEMESSAGE_H

#include "SessionMessage.h"

#include "Result.h"

class AddMessageResponseMessage : public SessionMessage
{
public:
    AddMessageResponseMessage(const QUuid& sessionId = QUuid(), Result result = Result::Invalid);

    Result getResult() const;
    void setResult(Result result);

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    Result addMessageResult;
};

#endif // ADDMESSAGERESPONSEMESSAGE_H
