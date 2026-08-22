#ifndef RESPONSEMESSAGE_H
#define RESPONSEMESSAGE_H

#include "SessionMessage.h"

#include <QUuid>

#include "ErrorInfo.h"
#include "MessageType.h"

class ResponseMessage: virtual public SessionMessage{
public:
    explicit ResponseMessage(const QUuid& messageSessionId = QUuid(),
                             const MessageType messageType = MessageType::Invalid,
                             const MessageType messageRespondedToMessageTypeType = MessageType::Invalid,
                             const ErrorInfo &messageErrorInfo = {ErrorCode::Undefined, ""});

    MessageType getRespondedToMessageType() const;
    ErrorInfo getErrorInfo() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    MessageType respondedToMessageType;
    ErrorInfo errorInfo;
};

#endif // RESPONSEMESSAGE_H
