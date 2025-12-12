#ifndef NEWSESSIONESTABLISHMENTMESSAGE_H
#define NEWSESSIONESTABLISHMENTMESSAGE_H

#include "SessionInitiationMessage.h"
#include "SessionMessage.h"
#include "MessageType.h"

class NewSessionEstablishmentMessage: public SessionInitiationMessage, public SessionMessage{
public:
    NewSessionEstablishmentMessage(const QUuid& initialUserId,
                                   const QUuid& sessionId,
                                   const MessageType messageType = MessageType::Invalid);

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;
};

#endif // NEWSESSIONESTABLISHMENTMESSAGE_H
