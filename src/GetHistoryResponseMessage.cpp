#include "GetHistoryResponseMessage.h"

#include <QJsonArray>

#include "MessageType.h"
#include "ChatMessageData.h"

const QString MESSAGES_KEY = "Messages";
const QString MESSAGE_ID_KEY = "Id";
const QString MESSAGE_USERNAME_KEY = "Username";
const QString MESSAGE_TEXT_KEY = "Text";
const QString MESSAGE_POST_TIME_KEY = "PostTime";

GetHistoryResponseMessage::GetHistoryResponseMessage() :
    SimpleMessage(MessageType::GetHistoryResponse),
    messages(std::vector<ChatMessageData>())
{

}

GetHistoryResponseMessage::GetHistoryResponseMessage(std::vector<ChatMessageData> messagesHistory) :
    SimpleMessage(MessageType::GetHistoryResponse),
    messages(std::move(messagesHistory))
{

}

std::vector<ChatMessageData> GetHistoryResponseMessage::getMessagesHistory() const
{
    return messages;
}

void GetHistoryResponseMessage::initRootObject(QJsonObject &rootObj)
{
    SimpleMessage::initRootObject(rootObj);

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
    auto initSuccessful = SimpleMessage::initFromRootObject(rootObj);
    if(!initSuccessful){
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
        messageData.id = messageJsonObject.value(MESSAGE_ID_KEY).toString();

        if(!messageJsonObject.contains(MESSAGE_USERNAME_KEY)){
            qWarning() << "Message contains no username";
            return false;
        }
        messageData.username = messageJsonObject.value(MESSAGE_USERNAME_KEY).toString();

        if(!messageJsonObject.contains(MESSAGE_TEXT_KEY)){
            qWarning() << "Message contains no text";
            return false;
        }
        messageData.text = messageJsonObject.value(MESSAGE_TEXT_KEY).toString();

        if(!messageJsonObject.contains(MESSAGE_POST_TIME_KEY)){
            qWarning() << "Message contains no post time";
            return false;
        }
        messageData.postTime = messageJsonObject.value(MESSAGE_POST_TIME_KEY).toString();

        messages.push_back(std::move(messageData));
    }

    return true;
}
