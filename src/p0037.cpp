#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>
#include <algorithm>

bool IsPrime(long target) {
    if( target < 2 ) {
	return false;
    }
    if( target == 2 ) {
	return true;
    }
    if( target % 2 == 0 ) {
	return false;
    }
    for( long i = 3; i < target/2; i += 2 ) {
	if( target % i == 0 ) {
	    return false;
	}
    }
    return true;
}

// Suppose the input is already prime.
bool IsLeftTruncatablePrime(long target)
{
    long divisor = 10;
    while( target % divisor != target ) {
	if( !IsPrime(target % divisor) ) {
	    return false;
	}
	divisor *= 10;
    }
    return true;
}

// Suppose the input is already prime
bool IsRightTruncatablePrime(long target)
{
    long divisor = 10;
    while( target / divisor > 0 ) {
	if( !IsPrime(target / divisor) ) {
	    return false;
	}
	divisor *= 10;
    }
    return true;
}

long SumVectorLong(std::vector<long>& v)
{
    long sum = 0;
    for( size_t index = 0; index < v.size(); ++index ) {
	sum += v[index];
    }
    return sum;
}

int main(int argc, char* argv[])
{
    std::vector<long> results;
    results.reserve(11); // There are only 11 primes that are both left-truncatable and right-truncatable
    
    for( long n = 11; n < 1000000; ++n ) {
	if( !IsPrime(n) ) {
	    continue;
	}
	if( IsLeftTruncatablePrime(n) && IsRightTruncatablePrime(n) ) {
	    results.push_back(n);
	    std::string sep = "";
	    std::cout << "results=[";
	    for( size_t index = 0; index < results.size(); ++index ) {
		std::cout << sep << results[index];
		sep = ", ";
	    }
	    std::cout << "];\n";
	}
	if( results.size() == 11 ) {
	    break;
	}
    }

    std::cout << "Sum of all left-/right-truncatable primes is " << SumVectorLong(results) << "\n";
}
