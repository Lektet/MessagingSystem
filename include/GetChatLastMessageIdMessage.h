#ifndef GETCHATLASTMESSAGEID_H
#define GETCHATLASTMESSAGEID_H

#include "SessionMessage.h"

class GetChatLastMessageIdMessage : public SessionMessage
{
public:
    explicit GetChatLastMessageIdMessage(const QUuid& sessionId = QUuid());
};

#endif // GETCHATLASTMESSAGEID_H
