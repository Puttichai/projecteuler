#include <algorithm>
#include <string>
#include <iostream>
#include "myutils.h"

// check if the given number has non-decreasing digits from left to right.
bool HasNonDecreasingDigits(int i)
{
    int latestdigit = 10;
    int checknum = i; // copy

    // digits have to be non-increasing from right to left
    while( checknum > 10 ) {
        int newdigit = checknum % 10;
        if( newdigit > latestdigit ) {
            return false;
        }
        latestdigit = newdigit;
        checknum = checknum / 10;
    }
    if( checknum > latestdigit ) {
        return false;
    }
    return true;
}

void GetSortedAllPrimePermutations(const int i, std::vector<int>& perm)
{
    std::string currentNumber;
    int number;
    perm.resize(0);
    for( size_t index = 0; index < 24; ++index ) {
        currentNumber = std::to_string(i);
        StringPermutation(index, currentNumber);
        number = std::stoi(currentNumber);

	if( std::find(perm.begin(), perm.end(), number) != perm.end() ) {
	    // Already in the list so skipping. (This is due to repeating digits.)
	    continue;
	}
	
        if( !IsPrime(number) ) {
            continue;
        }
        perm.push_back(number);
    }
    if( perm.size() > 0 ) {
	std::sort(perm.begin(), perm.end());
    }
}

bool HasArithmaticSequence(const std::vector<int>& perm, std::vector<int>& seq)
{
    seq.resize(0);
    for( size_t i = 0; i < perm.size() - 2; ++i ) {
	for( size_t j = i + 1; j < perm.size() - 1; ++j ) {
	    for( size_t k = j + 1; k < perm.size(); ++k ) {
		if( perm[k] - perm[j] == perm[j] - perm[i] ) {
		    seq.push_back(perm[i]);
		    seq.push_back(perm[j]);
		    seq.push_back(perm[k]);
		    return true;
		}
	    }	    
	}
    }
    return false;
}

int main(int argc, char* argv[])
{
    std::vector<int> perm;
    perm.reserve(24); // 4!
    std::vector<int> seq;

    std::stringstream ss;
    
    for( int i = 1000; i < 10000; ++i ) {
        if( !HasNonDecreasingDigits(i) ) {
            continue;
        }

        GetSortedAllPrimePermutations(i, perm);
	if( perm.size() < 3 ) {
	    continue;
	}
	if( 0 ) {
	    ss.str(""); ss.clear();
	    SerializeValues(ss, perm);
	    std::cout << "i=" << i << ", perm.size()=" << perm.size() << ", " << ss.str() << "\n";
	}
	
        if( HasArithmaticSequence(perm, seq) ) {
            std::cout << "i=" << i << ": found an arithmatic sequence ";
            std::string delim = "";
            for( size_t index = 0; index < seq.size(); ++index ) {
                std::cout << delim << seq[index];
                delim = ", ";
            }
            std::cout << "\n";
        }
    }
}
