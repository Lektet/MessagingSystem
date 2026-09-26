#ifndef GETCHATMESSAGEID_H
#define GETCHATMESSAGEID_H

#include "SessionMessage.h"

class GetChatFirstMessageIdMessage : public SessionMessage
{
public:
    explicit GetChatFirstMessageIdMessage(const QUuid& sessionId = QUuid());
};

#endif // GETCHATMESSAGEID_H
