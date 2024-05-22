#ifndef REQUESTTYPE_H
#define REQUESTTYPE_H

#include <QString>

enum class MessageType{
    Invalid,
    GetHistory,
    GetHistoryResponse,
    SendMessage,
    SendMessageResponse,
    Notification
};

QString messageTypeToString(const MessageType val);
MessageType messageTypeFromString(const QString &requestType);

#endif // REQUESTTYPE_H
