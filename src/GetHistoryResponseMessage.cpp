#include "GetHistoryResponseMessage.h"

#include "MessageType.h"

const QString MESSAGES_KEY = "Messages";

GetHistoryResponseMessage::GetHistoryResponseMessage() :
    SimpleMessage(MessageType::GetHistoryResponse)
{

}

void GetHistoryResponseMessage::setMessages(const QString &messages)
{
    messagesHistory = messages;
}

QString GetHistoryResponseMessage::getMessagesHistory() const
{
    return messagesHistory;
}

void GetHistoryResponseMessage::initRootObject(QJsonObject &rootObj)
{
    rootObj.insert(MESSAGES_KEY, messagesHistory);
}

bool GetHistoryResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    auto initSuccessful = SimpleMessage::initFromRootObject(rootObj);
    if(!initSuccessful){
        return false;
    }

    if(!rootObj.contains(MESSAGES_KEY)){
        qDebug() << "JSON root object contains no messages";
        return false;
    }

    messagesHistory = rootObj.value(MESSAGES_KEY).toString();
    return true;
}
