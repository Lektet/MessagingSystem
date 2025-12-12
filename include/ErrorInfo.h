#ifndef ERRORINFO_H
#define ERRORINFO_H

#include "QJsonObject"

#include "ErrorCode.h"

struct ErrorInfo{
    ErrorCode errorCode;
    QString errorDescription;
};

void saveErrorInfoToJson(QJsonObject& obj, const ErrorInfo& errorInfo);
bool loadErrorInfoFromJson(ErrorInfo& errorInfo, const QJsonObject& obj);


#endif // ERRORINFO_H
