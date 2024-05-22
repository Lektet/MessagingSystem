#ifndef UTILS_H
#define UTILS_H

#include <QString>

#include <map>

template<typename T>
T keyFromStringValue(const std::map<T, QString> &map, const QString &val, T defaultKey){
    for(auto &pair : map){
        if(pair.second == val){
            return pair.first;
        }
    }
    return defaultKey;
}

#endif // UTILS_H
