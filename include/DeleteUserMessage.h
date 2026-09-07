#ifndef DELETEUSERMESSAGE_H
#define DELETEUSERMESSAGE_H

#include "SessionMessage.h"

class DeleteUserMessage: public SessionMessage{
public:
    explicit DeleteUserMessage(const QUuid& sessionId = QUuid(),
                   const QString& userToDelete = QString());

    QString getUsername() const;

protected:
    virtual void initRootObject(QJsonObject &rootObj) const override;
    virtual bool initFromRootObject(const QJsonObject &rootObj) override;

private:
    QString username;
};

#endif // DELETEUSERMESSAGE_H
