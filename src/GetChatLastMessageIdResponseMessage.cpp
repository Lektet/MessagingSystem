#include "GetChatLastMessageIdResponseMessage.h"

GetChatLastMessageIdResponseMessage::GetChatLastMessageIdResponseMessage(const QUuid &sessionId,
                                                                         const QString &messageId,
                                                                         const ErrorInfo &errorInfo):
    GetChatMessageIdResponse(sessionId,
                             MessageType::GetChatLastMessageIdResponse,
                             messageId,
                             errorInfo)
{

}
