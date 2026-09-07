#ifndef NEWSESSIONSUCCESSRESPONSEMESSAGE_H
#define NEWSESSIONSUCCESSRESPONSEMESSAGE_H

#include "NewSessionEstablishmentMessage.h"
#include "ResponseMessage.h"

#include "UserRole.h"

class NewSessionResponseMessage: public NewSessionEstablishmentMessage, public ResponseMessage
{
public:
    explicit NewSessionResponseMessage(const QUuid& initialUserId = QUuid(),
                                     const QUuid& sessionId = QUuid(),
                                     const UserRole role = UserRole::Undefined,
                                     const ErrorInfo& messageErrorInfo = {ErrorCode::NoError, ""});

    UserRole getUserRole();

protected:
    virtual void initRootObject(QJsonObject &rootObj) const override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    UserRole userRole;
};

#endif // NEWSESSIONSUCCESSRESPONSEMESSAGE_H
