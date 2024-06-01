#include "GetHistoryResponseMessage.h"

#include "MessageType.h"

const QString MESSAGES_KEY = "Messages";

GetHistoryResponseMessage::GetHistoryResponseMessage() :
    SimpleMessage(MessageType::GetHistoryResponse)
{

}

GetHistoryResponseMessage::GetHistoryResponseMessage(const QJsonArray &messages) :
    SimpleMessage(MessageType::GetHistoryResponse),
    messagesHistory(messages)
{

}

QJsonArray GetHistoryResponseMessage::getMessagesHistory() const
{
    return messagesHistory;
}

void GetHistoryResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    rootObj.insert(MESSAGES_KEY, messagesHistory);
}

bool GetHistoryResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    auto initSuccessful = SimpleMessage::initFromRootObject(rootObj);
    if(!initSuccessful){
        qDebug() << "Parent init failed";
        return false;
    }

    if(!rootObj.contains(MESSAGES_KEY)){
        qDebug() << "JSON root object contains no messages";
        return false;
    }

    if(!rootObj.value(MESSAGES_KEY).isArray()){
        qDebug() << "Wrong messages format";
        return false;
    }

    messagesHistory = rootObj.value(MESSAGES_KEY).toArray();
    return true;
}
