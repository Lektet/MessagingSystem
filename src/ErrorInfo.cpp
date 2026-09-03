#include "ErrorInfo.h"

#include "MessageUtils.h"

#include <QDebug>

const QString RESULT_INFO_OBJECT_KEY = "ResultInfo";
const QString RESULT_CODE_KEY = "ResultCode";
const QString ERROR_DESCRIPTION_KEY = "ErrorDescription";

void saveErrorInfoToJson(QJsonObject &obj, const ErrorInfo &errorInfo)
{
    QJsonObject errorDataObj;
    errorDataObj.insert(RESULT_CODE_KEY, errorCodeToString(errorInfo.errorCode));
    errorDataObj.insert(ERROR_DESCRIPTION_KEY, errorInfo.errorDescription);

    obj.insert(RESULT_INFO_OBJECT_KEY, errorDataObj);
}

bool loadErrorInfoFromJson(ErrorInfo &errorInfo, const QJsonObject &obj)
{    
    if(!obj.contains(RESULT_INFO_OBJECT_KEY)){
        qWarning() << "Json contains no key for error data";
        return false;
    }

    if(!obj.value(RESULT_INFO_OBJECT_KEY).isObject()){
        qWarning() << "Json error data value is not object";
        return false;
    }

    auto errorDataObj = obj.value(RESULT_INFO_OBJECT_KEY).toObject();

    bool success = true;
    auto resultCodeStr = MessageUtils::getStringFromJsonObject(errorDataObj, RESULT_CODE_KEY, success);
    if(!success){
        return false;
    }
    errorInfo.errorCode = errorCodeFromString(resultCodeStr);

    auto errorDescription = MessageUtils::getStringFromJsonObject(errorDataObj, ERROR_DESCRIPTION_KEY, success);
    if(!success){
        return false;
    }
    errorInfo.errorDescription = std::move(errorDescription);

    return true;
}


QDebug operator<<(QDebug debug, const ErrorInfo &errorInfo)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << '(' << errorCodeToString(errorInfo.errorCode) <<
        ", " << errorInfo.errorDescription << ')';

    return debug;
}
