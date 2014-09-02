/*
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If d_n represents the nth digit of the fractional part, find the value of the following expression.

d_1 × d_10 × d_100 × d_1000 × d_10000 × d_100000 × d_1000000
*/

#include <iostream>
#include "utilities/strfun.h"

using namespace std;

int main(void)
{
	unsigned int counter = 0;
	unsigned char chars[1000000];
	
	for (unsigned int i = 1; i <= 1000000; ++i) {
		char *number = uitoa(i);
		unsigned int len = strlen(number);
		
		for (unsigned int j = 0; j < len && counter < 1000000; ++j, ++counter) {
			chars[counter] = number[j] - '0';
		}
	}
		
	cout << (chars[0] * chars[9] * chars[99] * chars[999] * chars[9999] * chars[99999] * chars[999999]) << endl;

	return 0;
}
