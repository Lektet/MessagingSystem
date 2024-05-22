#include "SendMessageResponseMessage.h"

#include "MessageType.h"
#include "Result.h"

const QString REQUEST_RESULT = "RequestResult";

SendMessageResponseMessage::SendMessageResponseMessage() :
    SimpleMessage(MessageType::SendMessageResponse)
{

}

void SendMessageResponseMessage::setResult(Result result)
{
    sendMessageResult = result;
}

Result SendMessageResponseMessage::getResult() const
{
    return sendMessageResult;
}

void SendMessageResponseMessage::initRootObject(QJsonObject &rootObj)
{
    rootObj.insert(REQUEST_RESULT, resultToString(sendMessageResult));
}

bool SendMessageResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    auto initSuccessful = SimpleMessage::initFromRootObject(rootObj);
    if(!initSuccessful){
        return false;
    }

    if(!rootObj.contains(REQUEST_RESULT)){
        qDebug() << "JSON root object contains no result";
        return false;
    }

    sendMessageResult = resultFromString(rootObj.value(REQUEST_RESULT).toString());
    return true;
}
