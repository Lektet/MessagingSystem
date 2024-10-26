#include "SendMessageResponseMessage.h"

#include "MessageType.h"
#include "Result.h"

const QString REQUEST_RESULT = "RequestResult";

SendMessageResponseMessage::SendMessageResponseMessage() :
    SimpleMessage(MessageType::SendMessageResponse)
{

}

SendMessageResponseMessage::SendMessageResponseMessage(Result result) :
    SimpleMessage(MessageType::SendMessageResponse),
    sendMessageResult(result)
{

}

Result SendMessageResponseMessage::getResult() const
{
    return sendMessageResult;
}

void SendMessageResponseMessage::setResult(Result result)
{
    sendMessageResult = result;
}

void SendMessageResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    rootObj.insert(REQUEST_RESULT, resultToString(sendMessageResult));
}

bool SendMessageResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    auto initSuccessful = SimpleMessage::initFromRootObject(rootObj);
    if(!initSuccessful){
        qWarning() << "Parent init failed";
        return false;
    }

    if(!rootObj.contains(REQUEST_RESULT)){
        qWarning() << "JSON root object contains no result";
        return false;
    }

    sendMessageResult = resultFromString(rootObj.value(REQUEST_RESULT).toString());
    return true;
}
