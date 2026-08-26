#ifndef ERRORCODE_H
#define ERRORCODE_H

#include <QString>

enum class ErrorCode{
    Undefined,
    NoError,
    BadRequest,
    Unauthorized,
    InternalError,
    AccessDenied,
    InvalidData,
    Conflict
};

QString errorCodeToString(const ErrorCode val);
ErrorCode errorCodeFromString(const QString &str);

#endif // ERRORCODE_H
