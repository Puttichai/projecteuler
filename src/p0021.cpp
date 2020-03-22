#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm> // find

void ComputeProperDivisors(int N, std::vector<int>& divisors) {
    divisors.clear();
    for( int n = 1; n <= N/2; ++n ) {
	if( N % n == 0 ) {
	    divisors.push_back(n);
	}
    }
    // std::cout << "There are " << divisors.size() << " proper divisors of " << N << "\n";
}

int SumIntVector(std::vector<int>& v) {
    int sum = 0;
    for( size_t i = 0; i < v.size(); ++i ) {
	sum += v[i];
    }
    return sum;
}

int main(int argc, char* argv[]) {
    int N = 10000;
    std::vector<int> checked; // collects all checked numbers that are larger than the current i
    std::vector<int> divisors;
    int sum = 0;
    for( int i = 2; i <= N; ++i ) {
	if( std::find(checked.begin(), checked.end(), i) != checked.end() ) {
	    continue;
	}
	
	ComputeProperDivisors(i, divisors);
	if( divisors.size() == 2 ) {
	    // Prime
	    continue;
	}
	int res = SumIntVector(divisors);
	checked.push_back(res);
	if( res == i ) {
	    std::cout << "Found a perfect number " << i << ".\n";
	    continue;
	}
	
	ComputeProperDivisors(res, divisors);
	if( divisors.size() == 2 ) {
	    // Prime
	    continue;
	}
	int res2 = SumIntVector(divisors);
	if( res2 == i ) {
	    std::cout << "Found amicable pair (" << i << ", " << res << ").\n";
	    sum += (i + res);
	}
    }

    std::cout << "Sum of all amicable pairs under " << N << " is " << sum << ".\n";

    return 0;
}
