#include <iostream>
#include <stdlib.h> // atoi
#include <string>

// return the length of the Collarz sequence that starts with n. Note that it is necessary to use long instead of int.
int CollatzLength(long n) {
    int len = 1; 
    while( n > 1 ) {
	if( (n % 2) == 0 ) {
	    n = n/2;
	}
	else {
	    n = 3*n + 1;
	}
	++len;
    }
    return len;
}

int main(int argc, char* argv[]) {
    if( argc < 2 ) {
	std::cout << "This program needs one argument\n";
	return 1;
    }
    int nmax = atoi(argv[1]);
    int maxlength = 0;
    int c = 0; // collatz number that give the current longest sequence
    for( int n = 1; n < nmax; ++n ) {
	int l = CollatzLength((long)n);
	if( l > maxlength ) {
	    c = n;
	    maxlength = l;
	    // std::cout << c << ", " << maxlength << "\n";
	}
    }
    std::cout << "The number under " << nmax << " that gives the longest Collatz sequence is " << c << " and the length is " << maxlength << "\n";
}
