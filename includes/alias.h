#ifndef ALIAS_H
#define ALIAS_H

#include<unordered_map>
#include<memory>
#include<vector>
#include<string>

using String = std::string;

template<typename T>
using Ptr = std::shared_ptr<T>;

template<typename T, typename G>
using Map = std::unordered_map<T, G>;

template<typename T>
using Vtr = std::vector<T>;

#endif
