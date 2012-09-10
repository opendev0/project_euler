/*
A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?
*/

#include "utilities/BigInt.h"
#include <iostream>

using namespace std;

typedef unsigned int uint;

int main(void)
{
	uint max = 0, loopSum;
	
	for (uint a = 11; a < 100; ++a) {
		for (uint b = 2; b < 100; ++b) {
			loopSum = BigInt(a).pow(b).digitSum();
			
			if (loopSum > max) {
				max = loopSum;
			}
		}
	}
	
	cout << "The maximum digital sum by considering natural numbers of the form a^b for a, b < 100 is " << max << '.' << endl;

	return 0;
}
