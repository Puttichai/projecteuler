#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm> // for std::remove

int ComputeTriangleNumber(int n)
{
    return n*(n + 1)/2;
}

int main(int argc, char* argv[])
{
    std::ifstream inputFile("p042_words.txt");
    std::vector<std::string> words;
    words.reserve(10000);
    if( inputFile.is_open() ) {
	std::string line;
	while( std::getline(inputFile, line) ) {
	    // Hold file content in a stringstream
	    std::stringstream ss(line);
	    std::string word;
	    // Read comma separated words
	    while( std::getline(ss, word, ',') ) {
		// Remove double quotes
		word.erase(std::remove(word.begin(), word.end(), '\"'), word.end());
		words.push_back(word);
	    }
	}
    }

    std::vector<int> triangleNumbers;
    triangleNumbers.push_back(ComputeTriangleNumber(1)); // first triangle number
    
    int numTriangleWords = 0;
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for( size_t iword = 0; iword < words.size(); ++iword ) {
	std::string& word = words[iword];
	// Compute score for this word
	int score = 0;
	for( size_t index = 0; index < word.size(); ++index ) {
	    size_t ipos = alphabet.find(word[index]);
	    score = score + (ipos + 1);
	}

	// Check if it is a triangle word
	while( score > triangleNumbers.back() ) {
	    // Only add more triangle numbers when needed
	    triangleNumbers.push_back( ComputeTriangleNumber(triangleNumbers.size() + 1) );
	}
	if( std::find(triangleNumbers.begin(), triangleNumbers.end(), score) != triangleNumbers.end() ) {
	    // std::cout << word << " is a triangle word of score " << score << "\n";
	    ++numTriangleWords;
	}	
    }
    std::cout << "There are a total of " << numTriangleWords << " triangle words\n";
}
