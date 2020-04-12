#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char* argv[])
{
    int curnumdigits = 1;
    int curdivisor = 1;
    int N = 1000000; // a million
    int curindex = 0;

    std::vector<int> markers; // store the position of the digits to check.
    markers.push_back(1);
    markers.push_back(10);
    markers.push_back(100);
    markers.push_back(1000);
    markers.push_back(10000);
    markers.push_back(100000);
    markers.push_back(1000000);
    int curmarkerindex = 0;

    int product = 1;
    for( int n = 1; n < N; ++n ) {
	int testnum = n;
	if( (int)(testnum / (10*curdivisor)) > 0 ) {
	    curdivisor *= 10;
	    ++curnumdigits;
	}
	
	int testdivisor = curdivisor;
	while( testdivisor > 1 ) {
	    if( curindex + 1 == markers[curmarkerindex] ) {
		int r = testnum / testdivisor;
		std::cout << markers[curmarkerindex] << "th digit is " << testnum << "/" << testdivisor << "=" << r << "\n";
		product *= r;
		++curmarkerindex;
		if( curmarkerindex == markers.size() ) {
		    break;
		}
	    }
	    testnum = testnum % testdivisor;
	    testdivisor /= 10;
	    ++curindex;
	}
	if( curindex + 1 == markers[curmarkerindex] ) {
	    int r = testnum / testdivisor;
	    std::cout << markers[curmarkerindex] << "th digit is " << testnum << "/" << testdivisor << "=" << r << "\n";
	    product *= r;
	    ++curmarkerindex;
	    if( curmarkerindex == markers.size() ) {
		break;
	    }
	}
	++curindex;
    }
    std::cout << "product is " << product << "\n";
}
