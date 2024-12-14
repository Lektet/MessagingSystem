#include "MessageType.h"

#include <map>

#include "utils.h"

std::map<MessageType, QString> requestTypeStrings = {
    {MessageType::Invalid, "Invalid"},
    {MessageType::GetHistory, "GetHistory"},
    {MessageType::GetHistoryResponse, "GetHistoryResponse"},
    {MessageType::SendMessage, "SendMessage"},
    {MessageType::SendMessageResponse, "SendMessageResponse"},
    {MessageType::Notification, "Notification"}
};

QString messageTypeToString(const MessageType val)
{
    return requestTypeStrings.at(val);
}



MessageType messageTypeFromString(const QString &requestType)
{
    return searchMapByValue(requestTypeStrings, requestType, MessageType::Invalid);
}
