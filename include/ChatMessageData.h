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

Q_DECLARE_METATYPE(ChatMessageData)

#endif // CHATMESSAGEDATA_H
