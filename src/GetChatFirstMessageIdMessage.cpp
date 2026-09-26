#include "GetChatFirstMessageIdMessage.h"

GetChatFirstMessageIdMessage::GetChatFirstMessageIdMessage(const QUuid &sessionId):
    SessionMessage(sessionId, MessageType::GetChatFirstMessageId)
{

}
