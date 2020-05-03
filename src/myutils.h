#ifndef MYUTILS_H
#define MYUTILS_H
#include <iostream>
#include <sstream>
#include <vector>

template <typename T>
void SerializeValues(std::stringstream& ss, std::vector<T>& values, std::string delim=", ")
{
    std::string curdelim = "";
    for( size_t index = 0; index < values.size(); ++index ) {
	ss << curdelim << values[index];
	curdelim = delim;
    }
}

template <typename T>
T SumVector(const std::vector<T>& v)
{
    T sum = 0;
    for( size_t index = 0; index < v.size(); ++index ) {
	sum = sum + v[index];
    }
    return sum;
}

#endif // MYUTILS_H
