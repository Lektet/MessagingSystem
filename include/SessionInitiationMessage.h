#ifndef SESSIONINITIATIONMESSAGE_H
#define SESSIONINITIATIONMESSAGE_H

#include "SimpleMessage.h"

#include <QUuid>

enum class MessageType;

class SessionInitiationMessage: virtual public SimpleMessage{
public:
    SessionInitiationMessage(const QUuid& initialUserId);

    QUuid getUserId();

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;


private:
    QUuid userId;
};

#endif // SESSIONINITIATIONMESSAGE_H
