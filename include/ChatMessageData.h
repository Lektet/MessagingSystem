#ifndef CHATMESSAGEDATA_H
#define CHATMESSAGEDATA_H

#include <QMetaType>

#include <QString>

struct ChatMessageData
{
    QString id;
    QString username;
    QString text;
    QString postTime;
};

// bool operator==(const ChatMessageData& lhs, const ChatMessageData& rhs){
//     return (lhs.id == rhs.id &&
//             lhs.username == rhs.username &&
//             lhs.text == rhs.text &&
//             lhs.postTime == rhs.postTime);
// }

Q_DECLARE_METATYPE(ChatMessageData)

#endif // CHATMESSAGEDATA_H
