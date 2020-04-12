#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>

bool IsPrime(int target)
{
    if( target < 0 ) {
	target = -target;
    }
    if( target < 2 ) {
	return false;
    }
    if( target == 2 ) {
	return true;
    }
    if( target % 2 == 0 ) {
	return false;
    }
    for( int i = 3; i < target/2; i += 2 ) {
	if( target % i == 0 ) {
	    return false;
	}
    }
    return true;
}

int EvalQuadratic(const int a, const int b, const int n)
{
    return n*n + a*n + b;
}

// This takes ages to run through all the loops. Need improvement.
int main(int argc, char* argv[])
{
    int maxConsecutive = 40; // we want more than this many consecutive primes
    int bestA, bestB;
    int bestNStart;
    for( int a = -999; a < 1000; ++a ) {
	std::cout << "\ncurrent a=" << a << "\n";
	for( int b = -999; b < 1000; ++b ) {

	    int nStart = 0;
	    while( nStart < 1000 ) {
		// std::cout << "nStart=" << nStart << "\n";
		// int val = EvalQuadratic(a, b, nStart);
		// if( !IsPrime(val) ) {
		//     ++nStart;
		//     continue;
		// }
		
		int nAim = nStart + maxConsecutive; // in order to break the record, eval at nAim has to be prime
		int val2 = EvalQuadratic(a, b, nAim);
		if( !IsPrime(val2) ) {
		    nStart = nAim + 1;
		    continue;
		}
		
		// Check if the range (nStart, nAim) is fine.
		bool bIsOk = true;
		int nCurCheck = nStart;
		while( nCurCheck < nAim )  {
		    int val3 = EvalQuadratic(a, b, nCurCheck);
		    if( !IsPrime(val3) ) {
			bIsOk = false;
			break;
		    }
		    ++nCurCheck;
		}
		if( !bIsOk ) {
		    nStart = nCurCheck + 1;
		    continue;
		}

		// Now the value in [nStart, nAim] are all ok. See how much we can go further.
		bIsOk = true;
		int nCurrentBestRun = nAim - nStart + 1;
		while( bIsOk ) {
		    ++nAim;
		    int val4 = EvalQuadratic(a, b, nAim);
		    if( IsPrime(val4) ) {
			++nCurrentBestRun;
		    }
		    else {
			bIsOk = false;
		    }
		}
		if( nCurrentBestRun > maxConsecutive ) {
		    bestA = a;
		    bestB = b;
		    maxConsecutive = nCurrentBestRun;
		    bestNStart = nStart;
		    std::cout << "current best=" << maxConsecutive << " at a=" << bestA << "; b=" << bestB << "; nStart=" << bestNStart << "; prod(a, b)=" << bestA*bestB << "\n";
		}
		nStart = nAim;
	    }
	}
    }
    std::cout << "maxConsecutive=" << maxConsecutive << " at a=" << bestA << "; b=" << bestB << "; nStart=" << bestNStart << "; prod(a, b)=" << bestA*bestB << "\n";
    return 0;
}

