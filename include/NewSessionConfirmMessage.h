#ifndef NEWSESSIONCONFIRMMESSAGE_H
#define NEWSESSIONCONFIRMMESSAGE_H

#include "NewSessionEstablishmentMessage.h"

class NewSessionConfirmMessage: public NewSessionEstablishmentMessage{
public:
    explicit NewSessionConfirmMessage(const QUuid& initialUserId = QUuid(),
                             const QUuid& sessionId = QUuid());

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;
};

#endif // NEWSESSIONCONFIRMMESSAGE_H
