#ifndef NEWSESSIONRESPONSEMESSAGE_H
#define NEWSESSIONRESPONSEMESSAGE_H

#include "NewSessionEstablishmentMessage.h"

class NewSessionResponseMessage: public NewSessionEstablishmentMessage{
public:
    NewSessionResponseMessage(bool usernameIsValid = false,
                              const QUuid& initialUserId = QUuid(),
                              const QUuid& sessionId = QUuid());

    bool getUsernameIsValid();


protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    bool isValid;
};

#endif // NEWSESSIONRESPONSEMESSAGE_H
