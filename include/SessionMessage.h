#ifndef SESSIONMESSAGE_H
#define SESSIONMESSAGE_H

#include "SimpleMessage.h"

#include <QUuid>

enum class MessageType;

class SessionMessage : virtual public SimpleMessage
{
public:
    SessionMessage(const QUuid& messageSessionId);

    QUuid getSessionId() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QUuid sessionId;
};


#endif // SESSIONMESSAGE_H
