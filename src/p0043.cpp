#include <algorithm>
#include <string> // stoi
#include <iostream>

/// from https://stackoverflow.com/a/2031708
/// k should be from 0 to s.size()! - 1 inclusive.
void permutation(int k, std::string &s) 
{
    for(int j = 1; j < s.size(); ++j) 
    {
        std::swap(s[k % (j + 1)], s[j]); 
        k = k / (j + 1);
    }
}

/// Check if the number represented by the given string satisfies all the properties.
bool Check(std::string& number)
{
    std::string testsubstr;

    // d2d3d4 is divisible by 2
    testsubstr = number.substr(1, 3);
    int d2d3d4 = std::stoi(testsubstr);
    if( d2d3d4 % 2 != 0 ) {
	return false;
    }

    // d3d4d5 is divisible by 3
    testsubstr = number.substr(2, 3);
    int d3d4d5 = std::stoi(testsubstr);
    if( d3d4d5 % 3 != 0 ) {
	return false;
    }

    // d4d5d6 is divisible by 5
    testsubstr = number.substr(3, 3);
    int d4d5d6 = std::stoi(testsubstr);
    if( d4d5d6 % 5 != 0 ) {
	return false;
    }

    // d5d6d7 is divisible by 7
    testsubstr = number.substr(4, 3);
    int d5d6d7 = std::stoi(testsubstr);
    if( d5d6d7 % 7 != 0 ) {
	return false;
    }

    // d6d7d8 is divisible by 11
    testsubstr = number.substr(5, 3);
    int d6d7d8 = std::stoi(testsubstr);
    if( d6d7d8 % 11 != 0 ) {
	return false;
    }

    // d7d8d9 is divisible by 13
    testsubstr = number.substr(6, 3);
    int d7d8d9 = std::stoi(testsubstr);
    if( d7d8d9 % 13 != 0 ) {
	return false;
    }

    // d8d9d10 is divisible by 17
    testsubstr = number.substr(7, 3);
    int d8d9d10 = std::stoi(testsubstr);
    if( d8d9d10 % 17 != 0 ) {
	return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
    std::string alldigits = "0123456789";
    int N = 3628800; // 10!

    std::string currentNumber;
    long sum = 0;
    for( int i = 0; i < N; ++i ) {
	currentNumber = alldigits; // copy
	permutation(i, currentNumber);
	// std::cout << "checking " << currentNumber << "\n";
	if( Check(currentNumber) ) {
	    long number = std::stol(currentNumber); // using stoi will crash since numbers are too large
	    sum = sum + number;
	    std::cout << currentNumber << " satisfies the properties\n";
	}
    }
    std::cout << "The sum of all the numbers that satify the properties is " << sum << "\n";
}
