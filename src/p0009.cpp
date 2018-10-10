#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>

bool IsPythagoreanTriplet(int a, int b, int c) {
    if( a*a + b*b == c*c ) {
	return true;
    }
    else {
	return false;
    }
}


// 
int main(int argc, char* argv[]) {
    bool bFound = false;
    for( int a = 1; a <= 998; ++a ) {
	for( int b = 1; b <= 998; ++b ) {
	    for( int c = 1; c <= 998; ++c ) {
		if( a + b + c == 1000) {
		    if( IsPythagoreanTriplet(a, b, c) ) {
			std::cout << "Found the triplet (a, b, c) = (" << a << ", " << b << ", " << c << ")\n";
			std::cout << "abc = " << a*b*c << "\n";
			bFound = true;
			break;
		    }
		}
	    }
	    if( bFound ) {
		break;
	    }
	}
	if( bFound ) {
	    break;
	}
    }
    return 0;
}
