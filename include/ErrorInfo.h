#ifndef ERRORINFO_H
#define ERRORINFO_H

#include <QMetaType>

#include "QJsonObject"

#include "ErrorCode.h"

struct ErrorInfo{
    ErrorCode errorCode = ErrorCode::NoError;
    QString errorDescription = "";
};

void saveErrorInfoToJson(QJsonObject& obj, const ErrorInfo& errorInfo);
bool loadErrorInfoFromJson(ErrorInfo& errorInfo, const QJsonObject& obj);

QDebug operator<<(QDebug debug, const ErrorInfo& errorInfo);

Q_DECLARE_METATYPE(ErrorInfo)

#endif // ERRORINFO_H
