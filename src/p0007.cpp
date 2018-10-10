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


// What is the 10001st prime?
int main(int argc, char* argv[]) {
    int icount = 0;
    int itest = 2;
    while( icount != 10001 ) {
	if( IsPrime(itest) ) {
	    icount += 1;
	}
	++itest;
    }
    
    std::cout << "The 10001st prime is " << itest - 1 << "\n";
    return 0;
}
