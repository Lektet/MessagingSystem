#ifndef ADDMESSAGERESPONSEMESSAGE_H
#define ADDMESSAGERESPONSEMESSAGE_H

#include "ResponseMessage.h"

#include "ErrorData.h"
#include "ErrorCode.h"

class AddMessageResponseMessage : public ResponseMessage
{
public:
    AddMessageResponseMessage(const QUuid& sessionId = QUuid(),
                              ResultInfo result = {ResultCode::Undefined, ""});

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;
};

#endif // ADDMESSAGERESPONSEMESSAGE_H
