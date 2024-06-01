#ifndef MESSAGESCREATION_H
#define MESSAGESCREATION_H

#include "SimpleMessage.h"

#include <memory>

namespace MessageUtils
{
    std::shared_ptr<SimpleMessage> createMessageFromJson(const QJsonDocument& document);

    MessageType getMessageType(const QJsonDocument& document);
}

#endif // MESSAGESCREATION_H
