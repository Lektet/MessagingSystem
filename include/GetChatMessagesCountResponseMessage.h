#ifndef GETCHATMESSAGESCOUNTRESPONSEMESSAGE_H
#define GETCHATMESSAGESCOUNTRESPONSEMESSAGE_H

#include "ResponseMessage.h"

#include <vector>

#include "ChatMessageData.h"

class GetChatMessagesCountResponseMessage : public ResponseMessage
{
public:
    explicit GetChatMessagesCountResponseMessage(const QUuid& sessionId = QUuid(),
                                            const int messageCount = 0,
                                            const ErrorInfo messageErrorInfo = {ErrorCode::NoError, ""});

    int getCount() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) const override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    int count;
};

#endif // GETCHATMESSAGESCOUNTRESPONSEMESSAGE_H
