#ifndef CHANGEUSERPASSWORDMESSAGE_H
#define CHANGEUSERPASSWORDMESSAGE_H

#include "SessionMessage.h"

class ChangeUserPasswordMessage: public SessionMessage{
public:
    explicit ChangeUserPasswordMessage(const QUuid& sessionId = QUuid(),
                   const QString& targetUsername = QString(),
                   const QString& newPassword = QString());

    QString getUsername() const;
    QString getPassword() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QString username;
    QString password;
};

#endif // CHANGEUSERPASSWORDMESSAGE_H
