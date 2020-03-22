#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream> // file
#include <algorithm> // sort

int main(int argc, char* argv[]) {

    // Read input
    std::ifstream infile("./p022_names.txt");
    std::string line;
    std::vector<std::string> names;
    while( std::getline(infile, line) ) {
	std::istringstream iss(line);
	while( iss ) {
	    std::string name;
	    if( !getline(iss, name, ',') ) {
		break;
	    }
	    names.push_back(name);
	}
    }
    std::sort(names.begin(), names.end());
    std::cout << "Input has " << names.size() << " names.\n";

    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int totalScore = 0;
    for( size_t iname = 0; iname < names.size(); ++iname ) {
	std::string currentName = names[iname];
	int currentScore = 0;
	for( size_t iletter = 0; iletter < currentName.length(); ++iletter ) {
	    int nLocation = alphabet.find(currentName[iletter]) + 1; // letter score is 1-indexed
	    currentScore += nLocation;
	}
	totalScore += (iname + 1) * currentScore;
    }
    std::cout << "Total score is " << totalScore << "\n";    
    return 0;
}
