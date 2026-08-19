#include <UserRole.h>

#include <map>

#include "utils.h"

std::map<UserRole, QString> userRoleStrings = {
    {UserRole::Undefined, "Invalid"},
    {UserRole::User, "User"},
    {UserRole::Admin, "Admin"}
};

QString userRoleToString(const UserRole val)
{
    return userRoleStrings.at(val);
}
UserRole userRoleFromString(const QString &str)
{
    return searchMapByValue(userRoleStrings, str, UserRole::Undefined);
}
