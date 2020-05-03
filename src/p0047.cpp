#include <vector>
#include <iostream>
#include "myutils.h"

// #define PRINT_PROGRESS

int CountDistinctFactors(const int num, const std::vector<int>& primeNumbers)
{
    int currentResult = num;
    int numFactors = 0;
    for( size_t index = 0; index < primeNumbers.size(); ++index ) {
	const int& m = primeNumbers[index];
	bool bFirst = true;
	while( currentResult % m == 0 ) {
	    if( bFirst ) {
		numFactors = numFactors + 1;
		bFirst = false;
	    }
	    currentResult = currentResult / m;
	}
	if( currentResult == 1 ) {
	    break;
	}
    }
    return numFactors;
}

int main(int argc, char* argv[])
{
    int searchLimit = 1000000;
    
    std::vector<int> primeNumbers;
    primeNumbers.reserve(searchLimit);

    int nConsecutive = 4;
    int nCurrent = 0;
    for( int n = 2; n < searchLimit; ++n ) {
	if( IsPrime(n) ) {
	    primeNumbers.push_back(n);
	    nCurrent = 0;
	    continue;
	}

	int nFactors = CountDistinctFactors(n, primeNumbers);
#ifdef PRINT_PROGRESS
	std::cout << "n=" << n << " has " << nFactors << " factors\n";
#endif
	if( nFactors != nConsecutive ) {
	    nCurrent = 0; // reset
	}
	else {
	    ++nCurrent;
	}
	if( nCurrent == nConsecutive ) {
	    std::cout << "Found " << nCurrent << " consecutive numbers that has " << nCurrent << " distinct factors starting from " << (n - nCurrent + 1) << "\n";
	    break;
	}
    }
}
