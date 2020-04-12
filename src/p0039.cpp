#include <iostream>
#include <stdlib.h> // atoi
#include <vector>
#include <string>
#include <algorithm>

/*
  Obligatory video from 3Blue1Brown: https://www.youtube.com/watch?v=QJYmyhnaaek

  For any point p = u + vi on a complex plane, where u and v are integers, the
  point p^2 = (u^2 - v^2) + 2uvi is always of an integer distance from the
  origin.

  The perimeter of such a right triangle is 2u^2 + 2uv. (Suppose that u > v.)
  
  Given a perimeter P. Then we have
  
      P   = 2u^2 + 2uv.
      P/2 = u(u + v)
  
  Therefore,
  
      1) P is an even number
      2) u is a factor of P and P = u*w where w < 2u.
      
  The Pythageorean triple from above is then (u^2 - v^2, 2uv, u^2 + v^2).

  u and v do not have to be whole numbers but 2uv has to.

  Probably too difficult to derive all triplets from the formula (i.e. more
  difficult than just using brute-force search).
 */

int FindPythagoreanTripleGivenPerimeter_Old(int P, std::vector< std::vector<int> >& solutions)
{
    if( P % 2 != 0 ) {
	// P has to be an even number.
	return 0;
    }
    int temp = P/2;
    for( int u = 2; u < temp; ++u ) {
	if( temp % u != 0 ) {
	    // u is not a factor of P/2
	    continue;
	}
	int temp2 = temp/u;
	if( temp2 >= 2*u || (temp2 <= u) ) {
	    // u does not satisfy condition 2.
	    continue;
	}

	int v = temp2 - u;
	std::vector<int> solution;
	solution.push_back(u*u - v*v);
	solution.push_back(2*u*v);
	solution.push_back(u*u + v*v);
	solutions.push_back(solution);
    }
    return (int)solutions.size();
}

bool IsTriangleIneqSatisfied(int a, int b, int c)
{
    if( a <= 0 || b <= 0 || c <= 0 ) {
	return false;
    }
    return c < a + b;
}

bool IsPythagoreanTriplet(int a, int b, int c)
{
    return (c*c - a*a - b*b) == 0;
}

int FindPythagoreanTripleGivenPerimeter(int P, std::vector< std::vector<int> >& solutions)
{
    for( int a = 1; a < P; ++a ) {
	for( int b = a; b < P; ++b ) {
	    int c = P - a - b;
	    if( !IsTriangleIneqSatisfied(a, b, c) ) {
		continue;
	    }

	    if( IsPythagoreanTriplet(a, b, c) ) {
		std::vector<int> solution;
		solution.push_back(a);
		solution.push_back(b);
		solution.push_back(c);
		solutions.push_back(solution);
	    }
	}
    }
    return (int)solutions.size();
}

void PrintSolutions(std::vector< std::vector<int> >& solutions)
{
    std::string sep1 = "";
    std::cout << "solutions = [";
    for( size_t index1 = 0; index1 < solutions.size(); ++index1 ) {
	std::cout << sep1 << "[";
	std::string sep2 = "";
	for( size_t index2 = 0; index2 < solutions[index1].size(); ++index2 ) {
	    std::cout << sep2 << solutions[index1][index2];
	    sep2 = ", ";
	}
	std::cout << "]";
	sep1 = ", ";
    }
    std::cout << "]\n";
    return;
}

int main(int argc, char* argv[])
{
    int bestnumsolutions = 0;
    int bestperimeter = 0;
    std::vector< std::vector<int> > bestsolutions;
    
    for( int P = 12; P <= 1000; ++P ) {
	std::vector< std::vector<int> > solutions;
	int numsolutions = FindPythagoreanTripleGivenPerimeter(P, solutions);
	if( numsolutions > bestnumsolutions ) {
	    bestnumsolutions = numsolutions;
	    bestsolutions = solutions;
	    bestperimeter = P;
	    std::cout << "current best perimeter is " << bestperimeter << ", having " << bestnumsolutions << " solutions\n";
	    PrintSolutions(bestsolutions);
	    std::cout << "\n";
	}
    }
}
