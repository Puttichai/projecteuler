#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>

void PrintResults(std::vector<int>& results, int ndigits)
{
    if( results.size() == 0 ) {
	return;
    }
    
    std::cout << "results=";
    for( int i = (int)results.size() - 1; i >= 0; -- i ) {
	if( results[i] == 0 ) {
	    for( int idigit = 0; idigit < ndigits; ++idigit ) {
		std::cout << "0";
	    }
	}
	else {
	    std::cout << results[i];
	}
	std::cout << " ";
    }
    std::cout << "\n";
    return;
}

int SumAllDigits(int N) {
    int sum = N % 10;
    while( N / 10 > 0 ) {
	N = N / 10;
	sum += N % 10;
    }
    return sum;
}

int main(int argc, char* argv[])
{
    std::vector<int> results;
    results.reserve(100);

    int c = 1e5;
    
    // Each element in the vector stores a x-digit block of the resulting number
    results.push_back(1);
    for( size_t n = 2; n <= 100; ++n ) {
	int carry = 0;
	for( size_t index = 0; index < results.size(); ++index ) {
	    results[index] *= n;
	    results[index] += carry;
	    carry = results[index] / c;
	    results[index] = results[index] % c;
	}
	if( carry > 0 ) {
	    results.push_back(carry);
	}
	// PrintResults(results, 5);
    }

    PrintResults(results, 5);

    int sum = 0;
    for( size_t index = 0; index < results.size(); ++index ) {
	sum += SumAllDigits(results[index]);
    }
    std::cout << "sum of all digits is " << sum << "\n";
}
