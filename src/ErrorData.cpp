#include "ErrorData.h"

#include "MessageUtils.h"

#include <QDebug>

const QString RESULT_INFO_OBJECT_KEY = "ResultInfo";
const QString RESULT_CODE_KEY = "ResultCode";
const QString ERROR_DESCRIPTION_KEY = "ErrorDescription";

void saveResultInfoToJson(QJsonObject &obj, const ResultInfo &errorData)
{
    QJsonObject errorDataObj;
    errorDataObj.insert(RESULT_CODE_KEY, resultCodeToString(errorData.resultCode));
    errorDataObj.insert(ERROR_DESCRIPTION_KEY, errorData.errorDescription);

    obj.insert(RESULT_INFO_OBJECT_KEY, errorDataObj);
}

bool loadResultInfoFromJson(ResultInfo &errorData, const QJsonObject &obj)
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
    if(errorDataObj.contains(RESULT_CODE_KEY)){
        qWarning() << "Json error data object contains no key for error code";
        return false;
    }

    auto resultCodeStr = MessageUtils::getStringFromJsonObject(errorDataObj, RESULT_CODE_KEY);
    if(resultCodeStr.isNull()){
        qWarning() << "Failed to get result code from Json object";
        return false;
    }
    errorData.resultCode = resultCodeFromString(resultCodeStr);

    auto errorDescription = MessageUtils::getStringFromJsonObject(errorDataObj, ERROR_DESCRIPTION_KEY);
    if(errorDescription.isNull()){
        qWarning() << "Failed to get error description from Json object";
    }
    errorData.errorDescription = std::move(errorDescription);

    return true;
}
