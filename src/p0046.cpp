#include <iostream>
#include <math.h>
#include "myutils.h"

int main(int argc, char* argv[])
{
    long searchLimit = 1000000;
    for( long num = 3; num < searchLimit; num += 2 ) {
	if( IsPrime(num) ) {
	    continue;
	}
	
	// Find out if num can be written as num = p + 2 * q**2 where p is prime
	long q = 1;
	long q2;
	bool bFound = false;
	for( ; q < num; ++q ) {
	    q2 = q*q;
	    if( q2 > num ) {
		break;
	    }
	    q2 = 2*q2;
	    if( q2 > num ) {
		break;
	    }
	    if( IsPrime(num - q2) ) {
		bFound = true;
		break;
	    }
	}
	if( !bFound ) {
	    std::cout << "Found a counterexample at n=" << num << "\n";
	    break;
	}
    }
}
