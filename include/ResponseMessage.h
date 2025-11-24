#ifndef RESPONSEMESSAGE_H
#define RESPONSEMESSAGE_H

#include "SessionMessage.h"

#include <QUuid>

#include "ErrorData.h"
#include "MessageType.h"

class ResponseMessage: public SessionMessage{
public:
    explicit ResponseMessage(const QUuid sessionId = QUuid(),
                             ResultInfo messageResultInfo = {ResultCode::Undefined, ""});

    ResultInfo getResultInfo() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj);
    virtual bool initFromRootObject(const QJsonObject &rootObj);

private:
    ResultInfo resultInfo;
};

#endif // RESPONSEMESSAGE_H
