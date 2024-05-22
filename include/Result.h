#ifndef RESULT_H
#define RESULT_H

#include <QString>

enum class Result{
    Invalid,
    Success,
    Fail
};

QString resultToString(const Result val);
Result resultFromString(const QString &result);

#endif // RESULT_H
