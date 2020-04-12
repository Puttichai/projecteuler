#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>
#include <algorithm>

bool ContainRepeatingDigits(long N, std::vector<int>& vcheck)
{
    int curdigit = N % 10;
    if( curdigit == 0 ) {
	return true;
    }
    if( curdigit - 1 >= (int)vcheck.size() ) {
	return true;
    }
    
    if( vcheck[curdigit - 1] > 0 ) {
	// Found a repeating digit
	return true;
    }
    vcheck[curdigit - 1] += 1;
    
    while( N / 10 > 0 ) {
	N = N / 10;
	curdigit = N % 10;
	if( curdigit == 0 ) {
	    return true;
	}
	if( curdigit - 1 >= (int)vcheck.size() ) {
	    return true;
	}
	if( vcheck[curdigit - 1] > 0 ) {
	    // Found a repeating digit
	    return true;
	}
	vcheck[curdigit - 1] += 1;
    }
    return false;
}

bool IsPrime(long target, long& factor) {
    if( target < 2 ) {
	return false;
    }
    if( target == 2 ) {
	return true;
    }
    if( target % 2 == 0 ) {
	return false;
    }
    for( long i = 3; i < target/2; i += 2 ) {
	if( target % i == 0 ) {
	    factor = i;
	    return false;
	}
    }
    return true;
}

// Find the largest pan-digital prime.
int main(int argc, char* argv[])
{
    long bestprime = 2;
    // Since sum_n n from 1 to 9 is 45, which is divisible by 3, it's not possible to have 9-digit pan digital prime.
    // By the same argument, we also cannot have 8-digit pan digital prime.
    std::vector<int> vcheck(7, 0);
    for( long p = 1000001; p < 10000000; p += 2 ) {
	std::fill(vcheck.begin(), vcheck.end(), 0);
	if( ContainRepeatingDigits(p, vcheck) ) {
	    continue;
	}
	// std::cout << "Found a pan digital number " << p << "\n";
	long factor;
	if( IsPrime(p, factor) ) {
	    bestprime = p;
	}
    }
    std::cout << "The largest pan-digital prime is " << bestprime << "\n";
}
