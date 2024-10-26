#ifndef NEWCHATMESSAGEDATA_H
#define NEWCHATMESSAGEDATA_H


#include <QMetaType>

#include <QString>

struct NewChatMessageData
{
public:
    NewChatMessageData(const QString& messageUsername = QString(),
                    const QString& messageText = QString());

    QString username;
    QString text;
};

Q_DECLARE_METATYPE(NewChatMessageData)

#endif // NEWCHATMESSAGEDATA_H
