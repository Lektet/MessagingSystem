#include "ErrorCode.h"

#include <map>

#include "utils.h"

std::map<ErrorCode, QString> errorCodeStrings = {
    {ErrorCode::Undefined, "Undefined"},
    {ErrorCode::NoError, "OK"},
    {ErrorCode::BadRequest, "BadRequest"},
    {ErrorCode::Unauthorized, "Unauthorized"},
    {ErrorCode::InternalError, "InternalError"},
    {ErrorCode::AccessDenied, "AccessDenied"},
    {ErrorCode::InvalidData, "InvalidData"},
    {ErrorCode::Conflict, "Conflict"},
    {ErrorCode::AuthError, "AuthError"}
};

QString errorCodeToString(const ErrorCode val)
{
    return errorCodeStrings.at(val);
}

ErrorCode errorCodeFromString(const QString &str)
{
    return searchMapByValue(errorCodeStrings, str, ErrorCode::Undefined);
}
