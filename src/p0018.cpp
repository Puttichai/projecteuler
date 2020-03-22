#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream> // file
#include <stdlib.h> // atoi
#include <algorithm> // max

int main(int argc, char* argv[]) {

    // Read input
    // std::ifstream infile("./p0018.data");
    std::ifstream infile("./p067_triangle.txt");
    std::string line;
    std::vector<std::vector<int> > rows;
    while( std::getline(infile, line) ) {
	std::istringstream iss(line);

	int num;
	std::vector<int> row;
	while( iss >> num ) {
	    row.push_back(num);
	}

	rows.push_back(row);
    }

    std::cout << "Input has " << rows.size() << "rows.\n";

    // Starting from the second last row up, replace each number of the row with the sum of itself and the best child.
    size_t numRows = rows.size();
    for( int irow = numRows - 2; irow >= 0; --irow ) {
	std::vector<int>& thisRow = rows.at(irow);
	size_t numCols = thisRow.size();

	for( int icol = 0; icol < thisRow.size(); ++icol ) {
	    thisRow[icol] += std::max(rows.at(irow + 1).at(icol), rows.at(irow + 1).at(icol + 1));
	}
    }

    std::cout << "max sum is " << rows[0][0] << "\n";
    
    return 0;
}

