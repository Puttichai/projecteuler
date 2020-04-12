#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>
#include <algorithm>

bool ContainRepeatingDigits(int N, std::vector<int>& vcheck)
{
    int curdigit = N % 10;
    if( curdigit > 0 ) {
	if( vcheck[curdigit - 1] > 0 ) {
	    // Found a repeating digit
	    return true;
	}
	vcheck[curdigit - 1] += 1;
    }
    else {
	return true;
    }
    
    while( N / 10 > 0 ) {
	N = N / 10;
	curdigit = N % 10;
	if( curdigit == 0 ) {
	    return true;
	}
	if( vcheck[curdigit - 1] > 0 ) {
	    // Found a repeating digit
	    return true;
	}
	vcheck[curdigit - 1] += 1;
    }
    return false;
}

int SumVectorInt(std::vector<int>& v)
{
    int sum = 0;
    for( size_t index = 0; index < v.size(); ++index ) {
	sum += v[index];
    }
    return sum;
}

// Find sum of products whose multiplicand, multiplier, and product can be written as 1 through 9 pandigital.
int main(int argc, char* argv[])
{
    std::vector<int> vcheck1(9, 0);

    std::vector<int> I, J, K;
    
    for( int i = 1; i < 10000; ++i ) {
	std::fill(vcheck1.begin(), vcheck1.end(), 0);
	if( ContainRepeatingDigits(i, vcheck1) ) {
	    continue;
	}
	for( int j = 1; j < i; ++j ) {
	    if( std::find(I.begin(), I.end(), j) != I.end() && std::find(J.begin(), J.end(), i) != J.end() ) {
		continue;
	    }
	    
	    std::vector<int> vcheck2 = vcheck1;
	    if( ContainRepeatingDigits(j, vcheck2) ) {
		continue;
	    }

	    int k = i * j;
	    if( ContainRepeatingDigits(k, vcheck2) ) {
		continue;
	    }

	    if( SumVectorInt(vcheck2) == 9 ) {
		I.push_back(i);
		J.push_back(j);
		K.push_back(k);
	    }
	}
    }

    for( size_t index = 0; index < I.size(); ++index ) {
	std::cout << "index=" << index << ": " << I[index] << " x " << J[index] << " = " << K[index] << "\n";
    }

    std::vector<int> products;
    products.reserve(K.size());
    std::cout << "products=[";
    std::string sep = "";
    for( size_t index = 0; index < K.size(); ++index ) {
	if( std::find(products.begin(), products.end(), K[index]) == products.end() ) {
	    products.push_back(K[index]);
	    std::cout << sep << K[index];
	    sep = ", ";
	}
    }
    std::cout << "];\nsum of all products is " << SumVectorInt(products) << "\n";
}
