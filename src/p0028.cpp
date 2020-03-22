#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream> // file
#include <algorithm>

int main(int argc, char* argv[]) {
    int N = 1001; // answer is 669171001

    int sum = 1;
    int currentValue = 1;
    for( int sideLength = 3; sideLength <= N; sideLength += 2 ) {
	int step = sideLength - 1;
	for( int index = 0; index < 4; ++index ) {
	    currentValue += step;
	    sum += currentValue;
	}
    }
    std::cout << "result is " << sum << "\n";
    
    return 0;
}
