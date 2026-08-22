#include "ResponseMessage.h"

#include "MessageType.h"

#include "MessageUtils.h"

const QString RESPONDED_TO_MESSAGE_TYPE_KEY = "RespondedToMessageType";

ResponseMessage::ResponseMessage(const QUuid& messageSessionId,
                                 const MessageType messageType,
                                 const MessageType messageRespondedToMessageType,
                                 const ErrorInfo& messageErrorInfo):
    SessionMessage(messageSessionId, messageType),
    respondedToMessageType(messageRespondedToMessageType),
    errorInfo(messageErrorInfo)
{

}

MessageType ResponseMessage::getRespondedToMessageType() const
{
    return respondedToMessageType;
}

ErrorInfo ResponseMessage::getErrorInfo() const
{
    return errorInfo;
}

void ResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);
    rootObj.insert(RESPONDED_TO_MESSAGE_TYPE_KEY, messageTypeToString(respondedToMessageType));
    saveErrorInfoToJson(rootObj, errorInfo);
}

bool ResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    bool success = true;
    auto messageTypeString = MessageUtils::getStringFromJsonObject(rootObj, RESPONDED_TO_MESSAGE_TYPE_KEY, success);
    if(!success){
        return false;
    }
    respondedToMessageType = messageTypeFromString(messageTypeString);

    if(!loadErrorInfoFromJson(errorInfo, rootObj)){
        qWarning() << "Error info loading from Json failed";
        return false;
    }

    return true;
}
