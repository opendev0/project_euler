/*
A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
*/

#include "utilities/BigInt.h"
#include <iostream>

using namespace std;

typedef unsigned int uint;

int main(void)
{
	uint max = 0;
	uint tmp;
	
	for (uint i = 11; i < 100; ++i) {
		for (uint j = 2; j < 100; ++j) {
			tmp = BigInt(i).pow(j).digitSum();
			
			if (tmp > max) {
				max = tmp;
			}
		}
	}
	
	cout << max << endl;

	return 0;
}
