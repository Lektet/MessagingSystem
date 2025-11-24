#include "AddMessageResponseMessage.h"

#include "MessageType.h"

AddMessageResponseMessage::AddMessageResponseMessage(const QUuid &sessionId, ResultInfo result) :
    SimpleMessage(MessageType::AddMessageResponse),
    ResponseMessage(sessionId, result)
{

}

void AddMessageResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);
    ResponseMessage::initRootObject(rootObj);
}

bool AddMessageResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!(SimpleMessage::initFromRootObject(rootObj) &&
          ResponseMessage::initFromRootObject(rootObj))){
        qWarning() << "Parent init failed";
        return false;
    }
    return true;
}
