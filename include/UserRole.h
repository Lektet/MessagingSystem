#ifndef USERROLE_H
#define USERROLE_H

#include <QMetaType>

enum class UserRole{
    Undefined,
    User,
    Admin,
    Guest
};

QString userRoleToString(const UserRole val);
UserRole userRoleFromString(const QString &str);

Q_DECLARE_METATYPE(UserRole);

#endif // USERROLE_H
