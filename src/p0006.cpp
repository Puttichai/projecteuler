#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h> // atoi

// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
int main(int argc, char* argv[]) {
    int diff = 0;
    for( int i = 1; i <= 100; ++i ) {
	for( int j = i + 1; j <= 100; ++j ) {
	    diff += 2*i*j;
	}
    }
    std::cout << diff << "\n";
    
    return 0;
}
