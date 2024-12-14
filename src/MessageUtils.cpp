#include "MessageUtils.h"

#include "GetHistoryMessage.h"
#include "GetHistoryResponseMessage.h"
#include "SendMessageMessage.h"
#include "SendMessageMessage.h"
#include "SendMessageResponseMessage.h"
#include "NotificationMessage.h"

#include "MessageType.h"

#include <QDebug>

const QString TYPE_KEY = "Type";

std::shared_ptr<SimpleMessage> invalidMessage(){
    return std::make_shared<SimpleMessage>(MessageType::Invalid);
}

std::shared_ptr<SimpleMessage> messageFromJson(std::shared_ptr<SimpleMessage> message, const QJsonDocument& document){
    if(message->fromJson(document)){
        return message;
    }
    return invalidMessage();
}

std::shared_ptr<SimpleMessage> MessageUtils::createMessageFromJson(const QJsonDocument &document)
{
    if(!document.isObject()){
        qDebug() << "Json document is invalid";
        return invalidMessage();
    }

    auto object = document.object();
    if(!object.contains(TYPE_KEY)){
        qDebug() << "Root object is invalid";
        return invalidMessage();
    }

    auto type = messageTypeFromString(object.value(TYPE_KEY).toString());
    switch (type) {
        case MessageType::Invalid:
            qDebug() << "Message type is invalid";
            return invalidMessage();
        case MessageType::GetHistory:{
            auto message = std::make_shared<GetHistoryMessage>();
            return messageFromJson(message, document);
        }
        case MessageType::GetHistoryResponse:{
            auto message = std::make_shared<GetHistoryResponseMessage>();
            return messageFromJson(message, document);
        }
        case MessageType::SendMessage:{
            auto message = std::make_shared<SendMessageMessage>();
            return messageFromJson(message, document);
        }
        case MessageType::SendMessageResponse:{
            auto message = std::make_shared<SendMessageResponseMessage>();
            return messageFromJson(message, document);
        }
        case MessageType::Notification:{
            auto message = std::make_shared<NotificationMessage>();
            return messageFromJson(message, document);
        }
        default:
            break;
    }
}

MessageType MessageUtils::getMessageType(const QJsonDocument &document)
{
    if(!document.isObject()){
        qWarning() << "Json document is invalid";
        return MessageType::Invalid;
    }

    auto object = document.object();
    if(object.isEmpty()){
        qWarning() << "Invalid JSON";
        return MessageType::Invalid;
    }

    if(!object.contains(TYPE_KEY)){
        qWarning() << "JSON object is invalid";
        return MessageType::Invalid;
    }

    return messageTypeFromString(object.value(TYPE_KEY).toString());
}
