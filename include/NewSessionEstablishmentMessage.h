#ifndef NEWSESSIONESTABLISHMENTMESSAGE_H
#define NEWSESSIONESTABLISHMENTMESSAGE_H

#include "SessionInitiationMessage.h"
#include "SessionMessage.h"
#include "MessageType.h"

class NewSessionEstablishmentMessage: public SessionInitiationMessage, virtual public SessionMessage{
public:
    explicit NewSessionEstablishmentMessage(const QUuid& initialUserId,
                                   const QUuid& sessionId,
                                   const MessageType messageType = MessageType::Invalid);

protected:
    virtual void initRootObject(QJsonObject &rootObj) const override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;
};

#endif // NEWSESSIONESTABLISHMENTMESSAGE_H
