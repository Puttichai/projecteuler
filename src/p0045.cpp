#include <vector>
#include <iostream>
#include <algorithm> // for std::find

long ComputeTriangleNumber(const long n)
{
    if( n % 2 == 0 ) {
	return (n/2)*(n + 1);
    }
    else {
	return n*((n + 1)/2);
    }
}

long ComputePentagonalNumber(const long n)
{
    if( n % 2 == 0 ) {
	return (n/2)*(3*n - 1);
    }
    else {
	return n*(3*((n - 1)/2) + 1);
    }
}

long ComputeHexagonalNumber(const long n)
{
    return n*(2*n - 1);
}

/*
  We can speed this up by *not* storing triangle numbers in a vector but instead computing it on-the-fly.
  Also, we could limit the lower bound of the search of pentagonal and hexagonal numbers.
*/
int main(int argc, char* argv[])
{
    size_t maxsize = 100000;
    std::vector<long> triangleNumbers;
    triangleNumbers.reserve(maxsize);
    while( triangleNumbers.size() < maxsize ) {
	triangleNumbers.push_back( ComputeTriangleNumber(285 + 1 + triangleNumbers.size()) );
    }
    
    std::vector<long> pentagonalNumbers;
    pentagonalNumbers.reserve(maxsize);
    while( pentagonalNumbers.size() < maxsize ) {
	pentagonalNumbers.push_back( ComputePentagonalNumber(165 + 1 + pentagonalNumbers.size()) );
    }
    
    std::vector<long> hexagonalNumbers;
    hexagonalNumbers.reserve(maxsize);
    while( hexagonalNumbers.size() < maxsize ) {
	hexagonalNumbers.push_back( ComputeHexagonalNumber(143 + 1 + hexagonalNumbers.size()) );
    }

    std::vector<long>::const_iterator it1, it2;
    for( int index = 0; index <  (int)triangleNumbers.size(); ++index ) {
	it1 = std::find(pentagonalNumbers.begin(), pentagonalNumbers.end(), triangleNumbers[index]);
	if( it1 == pentagonalNumbers.end() ) {
	    continue;
	}

	it2 = std::find(hexagonalNumbers.begin(), hexagonalNumbers.end(), triangleNumbers[index]);
	if( it2 == hexagonalNumbers.end() ) {
	    continue;
	}

	std::cout << "found T" << (index + 285 + 1) << " = P" << (it1 - pentagonalNumbers.begin() + 165 + 1) << " = H" << (it2 - hexagonalNumbers.begin() + 143 + 1) << " = " << triangleNumbers[index] << "\n";
	break;
    }
}
