#include "MessageType.h"

#include <map>

#include "utils.h"

std::map<MessageType, QString> requestTypeStrings = {
    {MessageType::Invalid, "Invalid"},
    {MessageType::GetHistory, "GetHistory"},
    {MessageType::GetHistoryResponse, "GetHistoryResponse"},
    {MessageType::AddMessage, "SendMessage"},
    {MessageType::AddMessageResponse, "SendMessageResponse"},
    {MessageType::Notification, "Notification"},
    {MessageType::NewSessionRequest, "NewSessionRequest"},
    {MessageType::NewSessionFailedResponse, "NewSessionFailedResponse"},
    {MessageType::NewSessionResponse, "NewSessionResponse"},
    {MessageType::NewSessionConfirm, "NewSessionConfirm"},
    {MessageType::BadRequestResponse, "BadRequestResponse"},
    {MessageType::AddUser, "AddUser"},
    {MessageType::AddUserResponse, "AddUserResponse"},
    {MessageType::ResponseMessage, "ResponseMessage"}
};

QString messageTypeToString(const MessageType val)
{
    return requestTypeStrings.at(val);
}



MessageType messageTypeFromString(const QString &requestType)
{
    return searchMapByValue(requestTypeStrings, requestType, MessageType::Invalid);
}
