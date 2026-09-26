#ifndef GETCHATLASTMESSAGEIDRESPONSE_H
#define GETCHATLASTMESSAGEIDRESPONSE_H

#include "GetChatMessageIdResponse.h"

class GetChatLastMessageIdResponseMessage : public GetChatMessageIdResponse
{
public:
    explicit GetChatLastMessageIdResponseMessage(const QUuid& sessionId = QUuid(),
                                                 const QString& messageId = QString(),
                                                 const ErrorInfo& errorInfo = {ErrorCode::NoError, ""});
};

#endif // GETCHATLASTMESSAGEIDRESPONSE_H
