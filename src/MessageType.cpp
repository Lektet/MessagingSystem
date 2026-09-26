#include "MessageType.h"

#include <map>

#include "utils.h"

std::map<MessageType, QString> requestTypeStrings = {
    {MessageType::Invalid, "Invalid"},
    {MessageType::GetChatMessages, "GetChatMessages"},
    {MessageType::GetChatMessagesResponse, "GetChatMessagesResponse"},
    {MessageType::GetChatMessagesCount, "GetChatMessagesCount"},
    {MessageType::GetChatMessagesCountResponse, "GetChatMessagesCountResponse"},
    {MessageType::GetChatMessagesNearId, "GetChatMessagesNearId"},
    {MessageType::GetChatMessagesNearIdResponse, "GetChatMessagesNearIdResponse"},
    {MessageType::GetChatFirstMessageId, "GetChatFirstMessageId"},
    {MessageType::GetChatLastMessageId, "GetChatLastMessageId"},
    {MessageType::GetChatFirstMessageIdResponse, "GetChatFirstMessageIdResponse"},
    {MessageType::GetChatLastMessageIdResponse, "GetChatLastMessageIdResponse"},
    {MessageType::CeaseViewingMessages, "CeaseViewingMessages"},
    {MessageType::CeaseViewingMessagesResponse, "CeaseViewingMessagesResponse"},
    {MessageType::AddMessage, "SendMessage"},
    {MessageType::AddMessageResponse, "SendMessageResponse"},
    {MessageType::AddUser, "AddUser"},
    {MessageType::AddUserResponse, "AddUserResponse"},
    {MessageType::DeleteUser, "DeleteUser"},
    {MessageType::DeleteUserResponse, "DeleteUserResponse"},
    {MessageType::ChangeUserPassword, "ChangeUserPassword"},
    {MessageType::ChangeUserPasswordResponse, "ChangeUserPasswordResponse"},
    {MessageType::Notification, "Notification"},
    {MessageType::NewSessionRequest, "NewSessionRequest"},
    {MessageType::NewSessionFailedResponse, "NewSessionFailedResponse"},
    {MessageType::NewSessionResponse, "NewSessionResponse"},
    {MessageType::NewSessionConfirm, "NewSessionConfirm"},
    {MessageType::NewSessionConfirmFailedResponse, "NewSessionConfirmFailedResponse"},
    {MessageType::BadRequestResponse, "BadRequestResponse"},
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
