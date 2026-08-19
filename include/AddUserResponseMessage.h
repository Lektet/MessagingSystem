#ifndef ADDUSERRESPONSEMESSAGE_H
#define ADDUSERRESPONSEMESSAGE_H

#include "SessionMessage.h"

class AddUserResponseMessage : public SessionMessage
{
public:
    AddUserResponseMessage(const QUuid& sessionId = QUuid(),
                              bool addUserResult = false);

    bool getResult() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

    bool result;
};

#endif // ADDUSERRESPONSEMESSAGE_H
