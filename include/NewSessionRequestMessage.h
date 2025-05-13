#ifndef NEWSESSIONREQUESTMESSAGE_H
#define NEWSESSIONREQUESTMESSAGE_H

#include "SessionInitiationMessage.h"

class NewSessionRequestMessage: public SessionInitiationMessage{
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
