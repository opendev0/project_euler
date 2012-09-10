/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include "utilities/intfun.h"
#include "utilities/BigInt.h"
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int uint;

int main(void)
{
	BigInt bi, bi2;
	uint numDigits;
	vector<uint> sums;
	uint result = 0;

	for (uint i = 3; i < 1000000; ++i) {
		bi = BigInt(i);
		bi2 = BigInt(0U);
		numDigits = bi.numDigits();
		
		for (uint j = 0; j < numDigits; ++j) {
			bi2 += factorial(bi[j]);
		}
		
		if (bi2 == i) {
			sums.push_back(i);
		}
	}
	
	for (uint i = 0; i < sums.size(); ++i) {
		result += sums[i];
		cout << sums[i] << endl;
	}
	
	cout << "The sum of all numbers which are equal to the sum of the factorial of their digits is " << result << '.' << endl;

	return 0;
}
