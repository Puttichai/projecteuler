#include <iostream>
#include <stdlib.h>

// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find
// the sum of the even-valued terms.
int main(int argc, char* argv[]) {
    if( argc < 2 ) {
	std::cout << "This program needs one argument\n";
	return 1;
    }
    int maxvalue = atoi(argv[1]);
    int fprevprev = 1, fprev = 1, fcur = 0;
    int sum = 0; // sum of even Fibonacci numbers
    while( fcur <= maxvalue ) {
	fcur = fprev + fprevprev;
	std::cout << "fcur=" << fcur << "\n";
	if( fcur % 2 == 0 ) {
	    sum += fcur;
	}
	fprevprev = fprev;
	fprev = fcur;
    }
    std::cout << sum << "\n";
    return 0;
}
