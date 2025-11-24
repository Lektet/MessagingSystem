#ifndef REQUESTTYPE_H
#define REQUESTTYPE_H

#include <QString>

enum class MessageType{
    Invalid,
    GetHistory,
    GetHistoryResponse,
    AddMessage,
    AddMessageResponse,
    Notification,
    NewSessionRequest,
    NewSessionResponse,
    NewSessionConfirm,
    Response
};

QString messageTypeToString(const MessageType val);
MessageType messageTypeFromString(const QString &requestType);

#endif // REQUESTTYPE_H
