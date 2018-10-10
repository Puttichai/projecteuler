#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h> // atoi


bool IsPalindrome(int num) {
    // Convert int to string
    std::stringstream ss;
    ss << num;
    std::string s = ss.str();

    size_t l = s.length();
    for( size_t index = 0; index < l/2; ++index ) {
	if( s[index] != s[l - 1 - index] ) {
	    return false;
	}
    }
    return true;
}


// What is the largest palindrome made from the product of 2 3-digit numbers ?
int main(int argc, char* argv[]) {
    int largestpalindrome = 1;
    for( int i = 900; i < 1000; ++i ) {
	for( int j = i; j < 1000; ++j ) {
	    int prod = i * j;
	    if( prod <= largestpalindrome ) {
		continue;
	    }
	    if( IsPalindrome(prod) ) {
		largestpalindrome = prod;
	    }
	}
    }

    std::cout << "The largest palindrome is " << largestpalindrome << "\n";
    return 0;
}
