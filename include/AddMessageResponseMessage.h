#ifndef ADDMESSAGERESPONSEMESSAGE_H
#define ADDMESSAGERESPONSEMESSAGE_H

#include "SessionMessage.h"

class AddMessageResponseMessage : public SessionMessage
{
public:
    AddMessageResponseMessage(const QUuid& sessionId = QUuid(),
                              bool addMessageResult = false);

    bool getResult() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

    bool result;
};

#endif // ADDMESSAGERESPONSEMESSAGE_H
