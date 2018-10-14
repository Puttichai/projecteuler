#include <iostream>
#include <stdlib.h> // atoi
#include <string>

long Factorial(int n) {
    if( n == 1 ) {
	return 1;
    }
    return n * Factorial(n - 1);
}

// How many such routes are there through a 20×20 grid?
int main(int argc, char* argv[]) {
    if( argc < 3 ) {
	std::cout << "This program needs two arguments\n";
	return 1;
    }
    int nrows = atoi(argv[1]);
    int ncolumns = atoi(argv[2]);

    // long nroutes = Factorial(nrows + ncolumns) / (Factorial(nrows) * Factorial(ncolumns));
    int n; // max(nrows, ncolumns)
    long denom; // assume that denom can hold the result of Factorial(n)
    if( nrows > ncolumns ) {
	n = nrows;
	denom = Factorial(ncolumns);
    }
    else {
	n = ncolumns;
	denom = Factorial(nrows);
    }

    // instead of taking the product for the numerator first then doing the division later, we do division whenever possible
    long numerator = 1;
    for( int i = nrows + ncolumns; i > n; --i ) {
	if( denom % i == 0 ) {
	    denom = denom/i;
	}
	else {
	    numerator *= i;
	}
    }
    std::cout << "The number of routes is " << numerator/denom << "\n";
}
