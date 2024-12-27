#include "AddMessageResponseMessage.h"

#include "MessageType.h"
#include "Result.h"

const QString REQUEST_RESULT = "RequestResult";

AddMessageResponseMessage::AddMessageResponseMessage() :
    SimpleMessage(MessageType::AddMessageResponse)
{

}

AddMessageResponseMessage::AddMessageResponseMessage(Result result) :
    SimpleMessage(MessageType::AddMessageResponse),
    addMessageResult(result)
{

}

Result AddMessageResponseMessage::getResult() const
{
    return addMessageResult;
}

void AddMessageResponseMessage::setResult(Result result)
{
    addMessageResult = result;
}

void AddMessageResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    rootObj.insert(REQUEST_RESULT, resultToString(addMessageResult));
}

bool AddMessageResponseMessage::initFromRootObject(const QJsonObject &rootObj)
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

    addMessageResult = resultFromString(rootObj.value(REQUEST_RESULT).toString());
    return true;
}
