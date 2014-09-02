/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:
	--> Have a look into the projects data-file

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
*/

#include <iostream>
#include <fstream>
#include "utilities/vector.h"

using namespace std;

typedef unsigned int uint;

vector<uint *>& readTriangle(char const *file)
{
	ifstream ifs(file);
	
	vector<uint *> *triangle = new vector<uint *>;
	
	for (uint i = 0; ifs.good(); ++i) {	
		uint *value = new uint[i + 1];
		
		for (uint j = 0; j <= i; ++j) {
			ifs >> value[j];
		}
		
		triangle->push_back(value);
	}
	
	return *triangle;
}

int main(void)
{
	vector<uint *> triangle = readTriangle("data/problem18.txt");	// for problem 67, just change file to problem67.txt
	
	const uint rows = triangle.size();
	
	for (uint i = (rows - 1); i; --i) {
		for (uint j = i; j; --j) {
			triangle[i - 1][j - 1] += ((triangle[i][j] > triangle[i][j - 1]) ? triangle[i][j] : triangle[i][j - 1]);
		}
	}
	
	cout << "The maximum total from the top to the bottom of the triangle is " << triangle[0][0] << '.' << endl;

	return 0;
}
