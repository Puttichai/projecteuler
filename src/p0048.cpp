#include <iostream>

int main(int argc, char* argv[])
{
    long cap = 1e10; // interested in only the last 10 digits
    long allResult = 0;
    for( long i = 1; i <= 1000; ++i ) {
	long currentResult = i;
	for( long exp = 2; exp <= i; ++exp ) {
	    currentResult = currentResult*i;
	    if( currentResult > cap ) {
		currentResult = currentResult % cap;
	    }
	}
	allResult = allResult + currentResult;
	if( allResult > cap ) {
	    allResult = allResult % cap;
	}
    }
    std::cout << "allResult=" << allResult << "\n";
}
