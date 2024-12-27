#ifndef UTILS_H
#define UTILS_H

#include <map>

template<typename Key, typename T>
Key searchMapByValue(const std::map<Key, T> &map, const T &val, Key defaultKey){
    for(auto &pair : map){
        if(pair.second == val){
            return pair.first;
        }
    }
    return defaultKey;
}

#endif // UTILS_H
