#ifndef SESSIONMESSAGE_H
#define SESSIONMESSAGE_H

#include "SimpleMessage.h"

#include <QUuid>

// enum class MessageType;
#include "MessageType.h"

class SessionMessage : public SimpleMessage
{
public:
    explicit SessionMessage(const QUuid& messageSessionId = QUuid(),
                   MessageType messageType = MessageType::Invalid);

    QUuid getSessionId() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) const override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QUuid sessionId;
};


#endif // SESSIONMESSAGE_H
