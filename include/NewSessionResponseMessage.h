#ifndef NEWSESSIONSUCCESSRESPONSEMESSAGE_H
#define NEWSESSIONSUCCESSRESPONSEMESSAGE_H

#include "NewSessionEstablishmentMessage.h"

#include "UserRole.h"

class NewSessionSuccessResponseMessage: public NewSessionEstablishmentMessage{
public:
    NewSessionSuccessResponseMessage(const QUuid& initialUserId = QUuid(),
                                     const QUuid& sessionId = QUuid(),
                                     const UserRole role = UserRole::Undefined);

    UserRole getUserRole();

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    UserRole userRole;
};

#endif // NEWSESSIONSUCCESSRESPONSEMESSAGE_H
