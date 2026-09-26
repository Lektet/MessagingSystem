#include "GetChatMessageIdResponse.h"

#include "MessageUtils.h"

const QString ID_KEY = "Id";

GetChatMessageIdResponse::GetChatMessageIdResponse(const QUuid &sessionId,
                                                   const MessageType messageType,
                                                   const QString &messageId,
                                                   const ErrorInfo &errorInfo) :
    ResponseMessage(sessionId, messageType, errorInfo),
    id(messageId)
{

}

QString GetChatMessageIdResponse::getMessageId() const
{
    return id;
}

void GetChatMessageIdResponse::initRootObject(QJsonObject &rootObj) const
{
    ResponseMessage::initRootObject(rootObj);

    rootObj.insert(ID_KEY, id);
}

bool GetChatMessageIdResponse::initFromRootObject(const QJsonObject &rootObj)
{
    if(!ResponseMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    bool success = true;
    id = MessageUtils::getStringFromJsonObject(rootObj, ID_KEY, success);
    if(!success){
        return false;
    }

    return true;
}
