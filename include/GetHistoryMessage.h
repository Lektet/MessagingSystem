#ifndef GETHISTORYMESSAGE_H
#define GETHISTORYMESSAGE_H

#include "SessionMessage.h"

enum class MessageType;

class GetHistoryMessage : public SessionMessage
{

public:
    GetHistoryMessage(const QUuid& sessionId = QUuid());

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;
};

#endif // GETHISTORYMESSAGE_H
