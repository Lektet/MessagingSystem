#include "MessageUtils.h"

#include "GetHistoryMessage.h"
#include "GetHistoryResponseMessage.h"
#include "AddMessageMessage.h"
#include "AddMessageMessage.h"
#include "AddMessageResponseMessage.h"
#include "NotificationMessage.h"
#include "NewSessionRequestMessage.h"
#include "NewSessionResponseMessage.h"
#include "NewSessionConfirmMessage.h"

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
        case MessageType::AddMessage:{
            auto message = std::make_shared<AddMessageMessage>();
            return messageFromJson(message, document);
        }
        case MessageType::AddMessageResponse:{
            auto message = std::make_shared<AddMessageResponseMessage>();
            return messageFromJson(message, document);
        }
        case MessageType::Notification:{
            auto message = std::make_shared<NotificationMessage>();
            return messageFromJson(message, document);
        }
        case MessageType::NewSessionRequest:{
            auto message = std::make_shared<NewSessionRequestMessage>();
            return messageFromJson(message, document);
        }
        case MessageType::NewSessionResponse:{
            auto message = std::make_shared<NewSessionResponseMessage>();
            return messageFromJson(message, document);
        }
        case MessageType::NewSessionConfirm:{
            auto message = std::make_shared<NewSessionConfirmMessage>();
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
