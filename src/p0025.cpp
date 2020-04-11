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

int main(int argc, char* argv[])
{
    std::vector<int> Fa, Fb, Fc;
    Fa.reserve(300);
    Fb.reserve(300);
    Fc.reserve(300);

    int c = 1e5;

    // Each element in the vector stores a x-digit block of the resulting number
    Fa.push_back(1);
    Fb.push_back(1);
    Fc.push_back(2);
    int firstindex = 3;
    while( Fc.size() < 201 ) {
	Fa.swap(Fb);
	Fb.swap(Fc);
	Fc.resize(0);
	++firstindex;
	size_t maxsize = Fb.size();
	int carry = 0;
	for( size_t index = 0; index < maxsize; ++index ) {
	    if( index >= Fa.size() ) {
		Fc.push_back(Fb[index]);
	    }
	    else {
		Fc.push_back(Fa[index] + Fb[index]);
	    }
	    Fc[index] += carry;
	    carry = Fc[index] / c;
	    Fc[index] = Fc[index] % c;
	}
	if( carry > 0 ) {
	    Fc.push_back(carry);
	}
	
	// PrintResults(Fc, 1);
	if( Fc.size() == 200 ) {
	    if( Fc.back() / (int)1e4 > 0 ) {
		// Found the number that has 1000 digits.
		break;
	    }
	}
    }

    PrintResults(Fc, 5);

    std::cout << "The first Fibonacci number that has 1000 digits is at index=" << firstindex << "\n";
}
