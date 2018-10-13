#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>
#include <math.h>

// return the index-th triangle number
int TriangleNumber(int index) {
    if( index == 1 ) {
	return 1;
    }
    else {
	return TriangleNumber(index - 1) + index;
    }
}

// return the number of divisors of the input
int NumDivisors(int target) {
    int num = 0;
    int bound = target;
    for( int i = 1; i < bound; ++i ) {
	if( target%i == 0 ) {
	    bound = target/i;
	    ++num;
	}
    }
    return 2 * num;
}

int main(int argc, char* argv[]) {
    if( argc < 2 ) {
	std::cout << "This program needs one argument\n";
	return 1;
    }
    int ndivisors = atoi(argv[1]);

    bool bFound = false;
    int i = 1; // current index
    int t = 0; // current triangle number
    int maxiter = 1000000;
    while( !bFound ) {
	if( i > maxiter ) {
	    break;
	}
	t = TriangleNumber(i);
	if( NumDivisors(t) > ndivisors ) {
	    bFound = true;
	    break;
	}
	++i;
    }
    if( bFound ) {
	std::cout << "The first triangle number to have over " << ndivisors << " divisors is " << t << "\n";
    }
    else {
	std::cout << "cannot find any triangle number that is less than " << maxiter << " to have over " << ndivisors << " divisors\n"; 
    }
    return 0;
}
