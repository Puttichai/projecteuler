#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>
#include <math.h>

bool IsPrime(long target) {
    if( target < 2 ) {
	return false;
    }
    if( target == 2 ) {
	return true;
    }
    if( target % 2 == 0 ) {
	return false;
    }
    for( long i = 3; i <= sqrt(target) + 1; i += 2 ) {
	if( target % i == 0 ) {
	    return false;
	}
    }
    return true;
}


// What is the 10001st prime?
int main(int argc, char* argv[]) {
    if( argc < 2 ) {
	std::cout << "This program needs one argument\n";
	return 1;
    }
    int maxnumber = atoi(argv[1]);

    long sum = 0;
    for( int p = 1; p < maxnumber; ++p ) {
	if( IsPrime(p) ) {
	    sum += p;
	}
    }
    std::cout << "The sum of all primes below " << maxnumber << " is " << sum << "\n";
    return 0;
}
