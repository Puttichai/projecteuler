#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream> // file
#include <algorithm>

void ComputeProperDivisors(int N, std::vector<int>& divisors)
{
    divisors.clear();
    for( int n = 1; n <= N/2; ++n ) {
	if( N % n == 0 ) {
	    divisors.push_back(n);
	}
    }
    // std::cout << "There are " << divisors.size() << " proper divisors of " << N << "\n";
}

int SumIntVector(std::vector<int>& v)
{
    int sum = 0;
    for( size_t i = 0; i < v.size(); ++i ) {
	sum += v[i];
    }
    return sum;
}

/// \brief Check if N can be written as a sum of 2 numbers from (sorted) v. Assume that max(v) < N.
/// return true if the number can be written as the specified sum.
bool CheckFn(int N, std::vector<int>& v)
{
    size_t index = 0;
    int currentValue = 0;
    if( v.size() < 2 ) {
	return false;
    }

    // v2: faster
    size_t maxSearchIndex = v.size() - 1; // ok since v.size() >= 2
    for( size_t index = 0; index < v.size(); ++index ) {
	int diff = N - v[index];
	if( diff > v[maxSearchIndex] ) {
	    continue;
	}
	else if( diff == v[maxSearchIndex] ) {
	    return true;
	}
	else {
	    if( index > maxSearchIndex ) {
		return false;
	    }
	    while( maxSearchIndex - 1 >= 0 && diff < v[maxSearchIndex] ) {
		maxSearchIndex = maxSearchIndex - 1;
	    }
	    if( diff == v[maxSearchIndex] ) {
		return true;
	    }
	}
    }
    return false;

    // v1: brute force
    // currentValue = v[index];
    // while( currentValue <= N/2 ) {
    // 	int diff = N - currentValue;
    // 	if( std::find(v.begin() + index, v.end(), diff) != v.end() ) {
    // 	    bFound = true;
    // 	    break;
    // 	}
    // 	++index;
    // 	currentValue = v[index];
    // }
    // return bFound;
}

int main(int argc, char* argv[]) {
    int N = 28123; // answer is 4179871

    std::vector<int> abundant; // vectors of all abundant numbers not greater than N
    std::vector<int> targets; // vectors of all numbers not greater than N that cannot be written as a sum of two abundant numbers
    std::vector<int> divisors;
    for( int n = 1; n <= N; ++n ) {
	// First, check if n can be written as a sum of two abundant numbers
	bool bFound = CheckFn(n, abundant);
	if( !bFound ) {
	    std::cout << n << " cannot be written as a sum of two abundant numbers.\n";
	    targets.push_back(n);
	}

	// Lastly, check if n is an abundant number
	ComputeProperDivisors(n, divisors);
	int sum = SumIntVector(divisors);
	if( sum > n ) {
	    // std::cout << "Found an abundant number " << n << "\n";
	    abundant.push_back(n);
	}
    }
    std::cout << "Sum of all numbers that cannot be written as a sum of two abundant numbers is " << SumIntVector(targets) << ".\n";
    
    return 0;
}
