#ifndef ADDUSERMESSAGE_H
#define ADDUSERMESSAGE_H

#include "SessionMessage.h"

#include "UserRole.h"

class AddUserMessage: public SessionMessage{
public:
    explicit AddUserMessage(const QUuid& sessionId = QUuid(),
                   const QString& newUsername = QString(),
                   const QString& newPassword = QString(),
                   const UserRole newUserRole = UserRole::User);

    QString getUsername() const;
    QString getPassword() const;
    UserRole getRole() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QString username;
    QString password;
    UserRole role;
};

#endif // ADDUSERMESSAGE_H
