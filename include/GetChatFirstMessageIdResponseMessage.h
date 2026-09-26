#ifndef GETCHATFIRSTMESSAGEIDRESPONSE_H
#define GETCHATFIRSTMESSAGEIDRESPONSE_H

#include "GetChatMessageIdResponse.h"

class GetChatFirstMessageIdResponseMessage : public GetChatMessageIdResponse
{
public:
    explicit GetChatFirstMessageIdResponseMessage(const QUuid& sessionId = QUuid(),
                                      const QString& messageId = QString(),
                                      const ErrorInfo& errorInfo = {ErrorCode::NoError, ""});
};

#endif // GETCHATFIRSTMESSAGEIDRESPONSE_H
