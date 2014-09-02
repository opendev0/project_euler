/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include <iostream>
#include "utilities/intfun.h"

using namespace std;

typedef unsigned int uint;

int main(void)
{
	uint result = 0;

	for (uint i = 3; i < 1000000; ++i) {
		uint sum = 0;
		
		for (uint n = i; n; n /= 10) {
			sum += factorial(n % 10);
		}
		
		if (sum == i) {
			result += sum;
		}
	}
	
	cout << "The sum of all numbers which are equal to the sum of the factorial of their digits is " << result << '.' << endl;

	return 0;
}
