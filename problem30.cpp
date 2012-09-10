/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include "utilities/BigInt.h"
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int uint;

uint pow(uint x, uint y)
{
	uint result = x;
	
	for (uint i = 1; i < y; ++i) {
		result *= x;
	}
	
	return result;
}

int main(void)
{
	vector<BigInt> numbers;
	BigInt sum(0U);
	
	for (BigInt i(10U); i < BigInt(1000000); ++i) {
		uint result = 0;
		
		for (uint j = 0; j < i.numDigits(); ++j) {
			result += pow(i[j], 5);
		}
		
		if (i == result) {
			numbers.push_back(i);
		}
	}
	
	for (uint i = 0; i < numbers.size(); ++i) {
		sum = (sum + numbers[i]);
	}
	
	cout << "The sum of all numbers that can be written as the sum of fifth powers of their digits is " << sum << '.' << endl;

	return 0;
}
