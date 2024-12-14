#include "Result.h"

#include <map>

#include "utils.h"

std::map<Result, QString> resultStrings = {
    {Result::Invalid, "Invalid"},
    {Result::Success, "Success"},
    {Result::Fail, "Fail"}
};

QString resultToString(const Result val)
{
    return resultStrings.at(val);
}

Result resultFromString(const QString &result)
{
    return searchMapByValue(resultStrings, result, Result::Invalid);
}
