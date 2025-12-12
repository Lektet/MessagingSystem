#include "GetHistoryResponseMessage.h"

#include <QJsonArray>

#include "MessageType.h"
#include "ChatMessageData.h"
#include "MessageUtils.h"

const QString MESSAGES_KEY = "Messages";
const QString MESSAGE_ID_KEY = "Id";
const QString MESSAGE_USERNAME_KEY = "Username";
const QString MESSAGE_TEXT_KEY = "Text";
const QString MESSAGE_POST_TIME_KEY = "PostTime";

// GetHistoryResponseMessage::GetHistoryResponseMessage() :
//     SimpleMessage(MessageType::GetHistoryResponse),
//     SessionMessage(QUuid()),
//     messages(std::vector<ChatMessageData>())
// {

// }

GetHistoryResponseMessage::GetHistoryResponseMessage(const QUuid &sessionId,
                                                     std::vector<ChatMessageData> messagesHistory) :
    SessionMessage(sessionId, MessageType::GetHistoryResponse),
    messages(std::move(messagesHistory))
{

}

std::vector<ChatMessageData> GetHistoryResponseMessage::getMessagesHistory() const
{
    return messages;
}

void GetHistoryResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SessionMessage::initRootObject(rootObj);
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

bool GetHistoryResponseMessage::initFromRootObject(const QJsonObject &rootObj)
{
    if(!SessionMessage::initFromRootObject(rootObj)){
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
        if(!messageJsonObject.contains(MESSAGE_ID_KEY)){
            qWarning() << "Message contains no id";
            return false;
        }
        auto id = MessageUtils::getStringFromJsonObject(messageJsonObject, MESSAGE_ID_KEY);
        if(id.isNull()){
            return false;
        }
        messageData.id = std::move(id);

        auto username = MessageUtils::getStringFromJsonObject(messageJsonObject, MESSAGE_USERNAME_KEY);
        if(username.isNull()){
            return false;
        }
        messageData.username = std::move(username);

        auto text = MessageUtils::getStringFromJsonObject(messageJsonObject, MESSAGE_TEXT_KEY);
        if(text.isNull()){
            return false;
        }
        messageData.text = std::move(text);

        auto postTime = MessageUtils::getStringFromJsonObject(messageJsonObject, MESSAGE_POST_TIME_KEY);
        if(postTime.isNull()){
            return false;
        }
        messageData.postTime = std::move(postTime);

        messages.push_back(std::move(messageData));
    }

    return true;
}
