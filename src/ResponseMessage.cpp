#include "ResponseMessage.h"

#include "MessageType.h"

ResponseMessage::ResponseMessage(const QUuid sessionId, ResultInfo messageResultInfo):
    SimpleMessage(),
    SessionMessage(sessionId),
    resultInfo(std::move(messageResultInfo))
{

}

ResultInfo ResponseMessage::getResultInfo() const
{
    return resultInfo;
}

void ResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);
    saveResultInfoToJson(rootObj, resultInfo);
}

bool ResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SimpleMessage::initFromRootObject(rootObj) ||
        !SessionMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    if(!loadResultInfoFromJson(resultInfo, rootObj)){
        qWarning() << "Error data loading from Json failed";
        return false;
    }

    return true;
}
