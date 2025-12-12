#include "BadRequestResponseMessage.h"

BadRequestResponseMessage::BadRequestResponseMessage(const QUuid &messageSessionId):
    ResponseMessage(messageSessionId,
                      MessageType::BadRequestResponse,
                      {ErrorCode::BadRequest, "Message is malformed"})
{

}

void BadRequestResponseMessage::initRootObject(QJsonObject &rootObj)
{
    ResponseMessage::initRootObject(rootObj);
}

bool BadRequestResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!ResponseMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }
    return true;
}
