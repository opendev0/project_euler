/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include <iostream>
#include "utilities/intfun.h"

using namespace std;

int main(void)
{
	unsigned int sum = 0;
	
	for (unsigned int i = 10; i < 1000000; ++i) {
		unsigned int result = 0;
		
		for (unsigned int j = i; j; j /= 10) {
			result += pow(j % 10, 5);
		}
		
		if (i == result) {
			sum += i;
		}
	}
	
	cout << "The sum of all numbers that can be written as the sum of fifth powers of their digits is " << sum << '.' << endl;

	return 0;
}
