#ifndef MYUTILS_H
#define MYUTILS_H
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

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

template <typename T>
bool IsPrime(T target) {
    if( target < 2 ) {
	return false;
    }
    if( target == 2 ) {
	return true;
    }
    if( target % 2 == 0 ) {
	return false;
    }
    double searchLimit = sqrt(target);
    for( T i = 3; i <= searchLimit + 1; i += 2 ) {
	if( target % i == 0 ) {
	    return false;
	}
    }
    return true;
}

/// from https://stackoverflow.com/a/2031708
/// k should be from 0 to s.size()! - 1 inclusive.
void StringPermutation(int k, std::string &s) 
{
    for(int j = 1; j < s.size(); ++j) 
    {
        std::swap(s[k % (j + 1)], s[j]); 
        k = k / (j + 1);
    }
}

int Factorial(int n, int r=2)
{
    if( n == 0 ) {
	return 1;
    }
    if( n == 1 || n == 2 || n == r ) {
	return n;
    }
    return n*Factorial(n - 1, r);
}

int Cnr(int n, int r)
{
    if( n - r > r ) {
	return Factorial(n, n - r)/Factorial(r);
    }
    else {
	return Factorial(n, r)/Factorial(n - r);
    }
}

#endif // MYUTILS_H
