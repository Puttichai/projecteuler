#include <iostream>
#include <sstream>
#include <vector>
#include "myutils.h"
#include <chrono> // need to compile with -std=c++11

/// \brief returns n where the division contains n-digit recurring cycles
int ComputeUnitFractionDecimalDigits(const int divisor, std::vector<int>& digits)
{
    // Detect a cycle by checking the current remainder
    std::vector<int> remainderApperanceIndices(divisor, -1);
    bool bRecurring = false;
    int n = 0;
    
    digits.clear();
    int currentRemainder = 1;
    remainderApperanceIndices[currentRemainder] = digits.size();

    int currentDividend;
    int currentQuotient;
    
    while( currentRemainder != 0 && !bRecurring ) {
	currentDividend = currentRemainder * 10;
	currentQuotient = currentDividend / divisor;
	digits.push_back(currentQuotient);
	currentRemainder = currentDividend % divisor;

	if( remainderApperanceIndices[currentRemainder] >= 0 ) {
	    bRecurring = true;
	    n = digits.size() - remainderApperanceIndices[currentRemainder];
	}
	else {
	    remainderApperanceIndices[currentRemainder] = digits.size();
	}
    }
    return n;
}

int main(int argc, char* argv[])
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    std::vector<int> digits;
    // std::stringstream ss;
    int maxdigits = 0;
    int bestdivisor = 0;
    for( int divisor = 1; divisor < 1000; ++divisor ) {
	int ndigits = ComputeUnitFractionDecimalDigits(divisor, digits);
	if( ndigits > maxdigits ) {
	    maxdigits = ndigits;
	    bestdivisor = divisor;
	}
	// SerializeValues(ss, digits);
	// std::cout << "divisor=" << divisor;
	// std::cout << "; n=" << ndigits;
	// std::cout << "; digits=[" << ss.str() << "];\n";
	// ss.str("");
	// ss.clear();
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "best divisor=" << bestdivisor << " giving " << maxdigits << "-digit recurring cycles\n";
    std::cout << "running time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]\n";

    return 0;
}
