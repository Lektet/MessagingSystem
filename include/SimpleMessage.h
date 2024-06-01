#ifndef SIMPLEMESSAGE_H
#define SIMPLEMESSAGE_H

#include "JsonSerializable.h"

enum class MessageType;

class SimpleMessage : public JsonSerializable
{
public:
    SimpleMessage(MessageType type);

    MessageType getMessageType() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    MessageType messageType;
};

#endif // SIMPLEMESSAGE_H
