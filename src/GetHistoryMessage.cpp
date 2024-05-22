#include "GetHistoryMessage.h"

#include "MessageType.h"

GetHistoryMessage::GetHistoryMessage() :
    SimpleMessage(MessageType::GetHistory)
{

}

void GetHistoryMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
}

bool GetHistoryMessage::initFromRootObject(const QJsonObject &rootObj)
{
    return SimpleMessage::initFromRootObject(rootObj);
}
