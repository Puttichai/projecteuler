#include <vector>
#include <iostream>
#include <algorithm>

// #define PRINT_PROGRESS

int ComputePentagonalNumber(const int n)
{
    return n*(3*n - 1)/2;
}


/*
  The current version is terribly slow. After some time, it gives the first pair as

  P2167 + P1020 = 7042750 + 1560090 = 8602840
  P2167 - P1020 = 7042750 - 1560090 = 5482660

  Not sure how to prove that this diff is the smallest.

  Need improvement.

*/
int main(int argc, char* argv[])
{
    size_t checkrange = 10000;
    int bestDiff = 10000;
    int bestIndex1 = -1;
    int bestIndex2 = -1;
    
    std::vector<int> pentagonalNumbers;
    pentagonalNumbers.reserve(checkrange);
    while( pentagonalNumbers.size() < checkrange ) {
	pentagonalNumbers.push_back( ComputePentagonalNumber(pentagonalNumbers.size() + 1) );
    }

    // Cache
    int checkindex = 0;
    int diff, sum;
    std::vector<int>::const_iterator idiff, isum;
    while( checkindex < checkrange ) {
	int nextPentagonalNumber = pentagonalNumbers[checkindex];
	for( int curCheckIndex = checkindex - 1; curCheckIndex >= 0; --curCheckIndex ) {
#ifdef PRINT_PROGRESS
	    std::cout << "Checking P" << (curCheckIndex + 1) << " = " << pentagonalNumbers[curCheckIndex] << " and P" << (checkindex + 1) << " = " << nextPentagonalNumber << "\n";
#endif
	    diff = nextPentagonalNumber - pentagonalNumbers[curCheckIndex];
	    idiff = std::find(pentagonalNumbers.begin(), pentagonalNumbers.begin() + checkindex, diff);
	    if( idiff == pentagonalNumbers.begin() ) {
		// The difference is not a pentagonal number
#ifdef PRINT_PROGRESS
		std::cout << "  diff=" << diff << " is not a pentagonal number\n";
#endif
		continue;		
	    }
	    
	    sum = nextPentagonalNumber + pentagonalNumbers[curCheckIndex];
	    isum = std::find(pentagonalNumbers.begin() + checkindex, pentagonalNumbers.end(), sum);
	    if( isum == pentagonalNumbers.end() ) {
		// The summation is not a pentagonal number
#ifdef PRINT_PROGRESS
		std::cout << "  sum=" << sum << " is not a pentagonal number\n";
#endif
		continue;
	    }

	    std::cout << "\nP" << (checkindex + 1) << " + P" << (curCheckIndex + 1) << " = " << nextPentagonalNumber << " + " << pentagonalNumbers[curCheckIndex] << " = " << sum << "\n";
	    std::cout << "P" << (checkindex + 1) << " - P" << (curCheckIndex + 1) << " = " << nextPentagonalNumber << " - " << pentagonalNumbers[curCheckIndex] << " = " << diff << "\n";
	    if( diff < bestDiff ) {
		bestDiff = diff;
		bestIndex1 = checkindex + 1;
		bestIndex2 = curCheckIndex;
	    }
	}
	++checkindex;
    }

    std::cout << "best (i, j)=(" << bestIndex1 << ", " << bestIndex2 << ")\n";
    std::cout << "bestDiff=" << bestDiff << "\n";
}
