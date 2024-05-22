#ifndef GETHISTORYMESSAGE_H
#define GETHISTORYMESSAGE_H

#include "SimpleMessage.h"

enum class MessageType;

class GetHistoryMessage : public SimpleMessage
{
public:
    GetHistoryMessage();

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;
};

#endif // GETHISTORYMESSAGE_H
