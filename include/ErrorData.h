#ifndef ERRORDATA_H
#define ERRORDATA_H

#include "QJsonObject"

#include "ErrorCode.h"

struct ResultInfo{
    ResultCode resultCode;
    QString errorDescription;
};

void saveResultInfoToJson(QJsonObject& obj, const ResultInfo& errorData);
bool loadResultInfoFromJson(ResultInfo& errorData, const QJsonObject& obj);


#endif // ERRORDATA_H
