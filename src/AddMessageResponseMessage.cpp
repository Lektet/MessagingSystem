#include "AddMessageResponseMessage.h"

#include "MessageType.h"
#include "Result.h"

const QString REQUEST_RESULT = "RequestResult";

AddMessageResponseMessage::AddMessageResponseMessage(const QUuid &sessionId, Result result) :
    SimpleMessage(MessageType::AddMessageResponse),
    SessionMessage(sessionId),
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
    SessionMessage::initRootObject(rootObj);
    rootObj.insert(REQUEST_RESULT, resultToString(addMessageResult));
}

bool AddMessageResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SimpleMessage::initFromRootObject(rootObj) &&
          SessionMessage::initFromRootObject(rootObj))){
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
