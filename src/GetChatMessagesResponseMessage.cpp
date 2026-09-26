#include "GetChatMessagesResponseMessage.h"

#include <QJsonArray>

#include "MessageType.h"
#include "ChatMessageData.h"
#include "MessageUtils.h"

const QString MESSAGES_KEY = "Messages";
const QString MESSAGE_ID_KEY = "Id";
const QString MESSAGE_USERNAME_KEY = "Username";
const QString MESSAGE_TEXT_KEY = "Text";
const QString MESSAGE_POST_TIME_KEY = "PostTime";

// GetChatMessagesResponseMessage::GetChatMessagesResponseMessage() :
//     SimpleMessage(MessageType::GetHistoryResponse),
//     SessionMessage(QUuid()),
//     messages(std::vector<ChatMessageData>())
// {

// }

GetChatMessagesResponseMessage::GetChatMessagesResponseMessage(const QUuid &sessionId,
                                                     std::vector<ChatMessageData> messagesHistory,
                                                               const MessageType messageType,
                                                               const ErrorInfo messageErrorInfo) :
    ResponseMessage(sessionId,
                      messageType,
                      messageErrorInfo),
    SessionMessage(sessionId, MessageType::GetChatMessagesResponse),
    messages(std::move(messagesHistory))
{

}

std::vector<ChatMessageData> GetChatMessagesResponseMessage::getMessagesHistory() const
{
    return messages;
}

void GetChatMessagesResponseMessage::initRootObject(QJsonObject &rootObj) const
{
    ResponseMessage::initRootObject(rootObj);
    QJsonArray messagesToSend;
    for(auto& messageObject: messages){
        QJsonObject messageJsonObject;
        messageJsonObject.insert(MESSAGE_ID_KEY, messageObject.id);
        messageJsonObject.insert(MESSAGE_USERNAME_KEY, messageObject.username);
        messageJsonObject.insert(MESSAGE_TEXT_KEY, messageObject.text);
        messageJsonObject.insert(MESSAGE_POST_TIME_KEY, messageObject.postTime);
        messagesToSend.append(messageJsonObject);
    }

    rootObj.insert(MESSAGES_KEY, messagesToSend);
}

bool GetChatMessagesResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!ResponseMessage::initFromRootObject(rootObj)){
        qWarning() << "Parent init failed";
        return false;
    }

    if(!rootObj.contains(MESSAGES_KEY)){
        qWarning() << "JSON root object contains no messages";
        return false;
    }

    if(!rootObj.value(MESSAGES_KEY).isArray()){
        qWarning() << "Wrong messages format";
        return false;
    }

    auto messagesArray = rootObj.value(MESSAGES_KEY).toArray();
    messages.clear();
    for(auto messageJsonValue: messagesArray){
        if(!messageJsonValue.isObject()){
            qWarning() << "Array element is not an object";
            return false;
        }        
        auto messageJsonObject = messageJsonValue.toObject();

        ChatMessageData messageData;
        bool success = true;
        auto id = MessageUtils::getStringFromJsonObject(messageJsonObject, MESSAGE_ID_KEY, success);
        if(!success){
            return false;
        }
        messageData.id = std::move(id);

        auto username = MessageUtils::getStringFromJsonObject(messageJsonObject, MESSAGE_USERNAME_KEY, success);
        if(!success){
            return false;
        }
        messageData.username = std::move(username);

        auto text = MessageUtils::getStringFromJsonObject(messageJsonObject, MESSAGE_TEXT_KEY, success);
        if(!success){
            return false;
        }
        messageData.text = std::move(text);

        auto postTime = MessageUtils::getStringFromJsonObject(messageJsonObject, MESSAGE_POST_TIME_KEY, success);
        if(!success){
            return false;
        }
        messageData.postTime = std::move(postTime);

        messages.push_back(std::move(messageData));
    }

    return true;
}
