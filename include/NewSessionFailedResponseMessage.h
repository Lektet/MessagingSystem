#ifndef NEWSESSIONFAILEDRESPONSEMESSAGE_H
#define NEWSESSIONFAILEDRESPONSEMESSAGE_H

#include "SimpleMessage.h"
#include "SessionInitiationMessage.h"


class NewSessionFailedResponseMessage: public SimpleMessage, public SessionInitiationMessage{
public:
    NewSessionFailedResponseMessage(const QUuid& initialUserId = QUuid());

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;
};

#endif // NEWSESSIONFAILEDRESPONSEMESSAGE_H
