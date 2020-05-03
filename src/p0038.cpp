#include <vector>
#include <iostream>
#include <string>

/// \brief return true if digits of num are all distinct from digits specificed in the vector digits.
bool CollectDigits(const int num, std::vector<int>& digits)
{
    int divisor = 10;
    int remainder = num % divisor;
    int quotient = num / divisor;

    if( remainder == 0 ) {
	return false;
    }
    if( digits[remainder - 1] > 0 ) {
	return false;
    }
    else {
	++digits[remainder - 1];
    }
    
    while( quotient > 0 ) {
	remainder = quotient % divisor;
	quotient = quotient / divisor;
	if( remainder == 0 ) {
	    return false;
	}
	if( digits[remainder - 1] > 0 ) {
	    return false;
	}
	else {
	    ++digits[remainder - 1];
	}
    }
    return true;
}

template <typename T>
T SumVector(const std::vector<T>& v)
{
    T sum = 0;
    for( size_t index = 0; index < v.size(); ++index ) {
	sum = sum + v[index];
    }
    return sum;
}

int main(int argc, char* argv[])
{
    std::vector<int> digits(9, 0);
    int bestNumber = 0;
    int bestMaxN = 0;
    
    for( int i = 1; i < 100000; ++i ) {
	bool bPandigital = false;
	int maxN = 0;
	std::fill(digits.begin(), digits.end(), 0);
	for( int n = 1; n < 10; ++n ) {
	    bool bDistinct = CollectDigits(i*n, digits);
	    if( !bDistinct ) {
		break;
	    }

	    // Check if the concatenated product so far forms a pandigital number
	    if( SumVector(digits) == 9 ) {
		bPandigital = true;
		maxN = n;
		break;
	    }
	}
	if( bPandigital ) {
	    std::cout << "Found a pandigital concatenated product at i=" << i << "\n";
	    for( int j = 1; j <= maxN; ++j ) {
		std::cout << "  " << i << " x " << j << " = " << i*j << "\n";
	    }
	    bestNumber = i;
	    bestMaxN = maxN;
	}
    }

    std::string result;
    for( int n = 1; n <= bestMaxN; ++n ) {
	result = result + std::to_string(bestNumber*n);
    }
    std::cout << "result = " << result << "\n";
}
