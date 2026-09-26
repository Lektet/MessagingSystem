#include "GetChatLastMessageIdMessage.h"

GetChatLastMessageIdMessage::GetChatLastMessageIdMessage(const QUuid &sessionId) :
    SessionMessage(sessionId, MessageType::GetChatLastMessageId)
{

}
