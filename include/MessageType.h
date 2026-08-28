#ifndef REQUESTTYPE_H
#define REQUESTTYPE_H

#include <QString>

enum class MessageType{
    Invalid,
    GetChatMessages,
    GetChatMessagesResponse,
    AddMessage,
    AddMessageResponse,
    AddUser,
    AddUserResponse,
    ChangeUserPassword,
    Notification,
    NewSessionRequest,
    NewSessionResponse,
    NewSessionFailedResponse,
    NewSessionConfirm,
    BadRequestResponse,
    ResponseMessage
};

QString messageTypeToString(const MessageType val);
MessageType messageTypeFromString(const QString &requestType);

#endif // REQUESTTYPE_H
