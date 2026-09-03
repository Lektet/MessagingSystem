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
    DeleteUser,
    DeleteUserResponse,
    ChangeUserPassword,
    ChangeUserPasswordResponse,
    Notification,
    NewSessionRequest,
    NewSessionResponse,
    NewSessionFailedResponse,
    NewSessionConfirm,
    NewSessionConfirmFailedResponse,
    BadRequestResponse,
    ResponseMessage
};

QString messageTypeToString(const MessageType val);
MessageType messageTypeFromString(const QString &requestType);

#endif // REQUESTTYPE_H
