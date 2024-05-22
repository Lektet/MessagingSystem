#ifndef SIMPLEMESSAGE_H
#define SIMPLEMESSAGE_H

#include "AbstractMessage.h"

enum class MessageType;

class SimpleMessage : public AbstractMessage
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
