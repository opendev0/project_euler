/*
The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

#include "utilities/strfun.h"
#include <iostream>

using namespace std;

int main(void)
{
	unsigned int result = 0;
	
	for (unsigned int i = 1; i < 1000000; ++i) {
		if (isPalindromic(uitoa(i)) && isPalindromic(dec2bin(i))) {
			result += i;
		}
	}
	
	cout << result << endl;
	
	return 0;
}
