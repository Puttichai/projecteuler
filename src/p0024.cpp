#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream> // file
#include <algorithm>

/// \brief Compute the factorial of a small number N.
int Factorial(int N) {
    if( N < 2 ) {
	return 1;
    }
    return N*Factorial(N - 1);
}

int main(int argc, char* argv[]) {
    int desiredPosition = 1000000 - 1;

    std::string perm = "0123456789";
    int len = perm.length();

    std::string result;

    // Loop to compute each position of the resulting string
    std::string currentString = perm;
    int currentSum = 0;
    for( size_t index = 0; index < len; ++index ) {
	int factorial = Factorial(len - (index + 1));
	int res = (desiredPosition - currentSum) / factorial;
	currentSum += factorial*res;
	result += currentString[res];
	currentString = currentString.substr(0, res) + currentString.substr(res + 1, currentString.length());
    }
    std::cout << "result is " << result << "\n";
}
