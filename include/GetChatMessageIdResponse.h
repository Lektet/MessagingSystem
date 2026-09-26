#ifndef GETCHATMESSAGEIDRESPONSE_H
#define GETCHATMESSAGEIDRESPONSE_H

#include "ResponseMessage.h"

class GetChatMessageIdResponse : public ResponseMessage
{
public:
    explicit GetChatMessageIdResponse(const QUuid& sessionId = QUuid(),
                                      const MessageType messageType = MessageType::Invalid,
                                      const QString& messageId = QString(),
                                      const ErrorInfo& errorInfo = {ErrorCode::NoError, ""});

    QString getMessageId() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) const override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QString id;
};

#endif // GETCHATMESSAGEIDRESPONSE_H
