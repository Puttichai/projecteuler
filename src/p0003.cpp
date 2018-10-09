#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>

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
    for( long i = 3; i < target/2; i += 2 ) {
	if( target % i == 0 ) {
	    return false;
	}
    }
    return true;
}

long FindLargestPrimeFactor(long target) {
    if( target < 2 ) {
	return 1;
    }
    else if( target == 2 ) {
	return 2;
    }
    for( long i = 3; i < target/2 + 1; i += 2 ) {
	if( target % i == 0 ) {
	    // Found a factor of target
	    long div = target / i;
	    long res1 = IsPrime(i) ? i : FindLargestPrimeFactor(i);
	    long res2 = IsPrime(div) ? div : FindLargestPrimeFactor(div);
	    if( res1 > res2 ) {
		return res1;
	    }
	    else {
		return res2;
	    }
	}
    }
    return target;
}

// What is the largest prime factor of the number 600851475143 ?
int main(int argc, char* argv[]) {
    if( argc < 2 ) {
	std::cout << "This program needs one argument\n";
	return 1;
    }
    long target = atol(argv[1]);
    std::vector<long> factors;

    long largestfactor = FindLargestPrimeFactor(target);
    std::cout << "The largest factor is " << largestfactor << "\n";
    return 0;
}
