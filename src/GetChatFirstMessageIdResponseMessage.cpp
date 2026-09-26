#include "GetChatFirstMessageIdResponseMessage.h"

GetChatFirstMessageIdResponseMessage::GetChatFirstMessageIdResponseMessage(const QUuid &sessionId,
                                                             const QString &messageId,
                                                             const ErrorInfo &errorInfo):
    GetChatMessageIdResponse(sessionId,
                             MessageType::GetChatFirstMessageIdResponse,
                             messageId,
                             errorInfo)
{

}
