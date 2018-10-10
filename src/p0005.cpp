#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h> // atoi

int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
int main(int argc, char* argv[]) {
    int res = 1;
    for( int i = 2; i <= 20; ++i ) {
	if( res % i == 0 ) {
	    continue;
	}
	else {
	    int gcd = GCD(res, i);
	    res *= (i/gcd);
	}
    }

    std::cout << res << "\n";
    
    return 0;
}
