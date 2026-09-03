#include "ResponseMessage.h"

#include "MessageType.h"

#include "MessageUtils.h"

ResponseMessage::ResponseMessage(const QUuid& messageSessionId,
                                 const MessageType messageType,
                                 const ErrorInfo& messageErrorInfo):
    SessionMessage(messageSessionId, messageType),
    errorInfo(messageErrorInfo)
{

}

ErrorInfo ResponseMessage::getErrorInfo() const
{
    return errorInfo;
}

void ResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);
    saveErrorInfoToJson(rootObj, errorInfo);
}

bool ResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    if(!loadErrorInfoFromJson(errorInfo, rootObj)){
        qWarning() << "Error info loading from Json failed";
        return false;
    }

    return true;
}
