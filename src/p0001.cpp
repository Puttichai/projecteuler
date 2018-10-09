#include <iostream>
#include <stdlib.h>

// Problem 1. Find the sum of all the multiples of 3 or 5 below 1000
int main(int argc, char* argv[]) {
    if( argc < 2 ) {
	return 1;
    }
    int sum = 0;
    for( int i = 1; i < atoi(argv[1]); ++i ) {
	if( (i % 3 == 0) || (i % 5 == 0) ) {
	    sum += i;
	}
    }
    std::cout << sum << "\n";
    return 0;
}
