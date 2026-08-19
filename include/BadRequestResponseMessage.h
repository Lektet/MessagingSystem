#ifndef BADREQUESTRESPONSEMESSAGE_H
#define BADREQUESTRESPONSEMESSAGE_H

#include "SessionMessage.h"
#include "ResponseMessage.h"

class BadRequestResponseMessage: public ResponseMessage{
public:
    explicit BadRequestResponseMessage(const QUuid& sessionId = QUuid());

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;
};

#endif // BADREQUESTRESPONSEMESSAGE_H
