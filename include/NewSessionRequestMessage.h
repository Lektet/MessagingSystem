#ifndef NEWSESSIONREQUESTMESSAGE_H
#define NEWSESSIONREQUESTMESSAGE_H

#include "SimpleMessage.h"
#include "SessionInitiationMessage.h"

class NewSessionRequestMessage: public SimpleMessage, public SessionInitiationMessage{
public:
    NewSessionRequestMessage(const QUuid& initialUserId = QUuid(),
                             const QString& authUsername = QString());

    QString getUsername() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QString username;
};

#endif // NEWSESSIONREQUESTMESSAGE_H
