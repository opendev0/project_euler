/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include "utilities/strfun.h"
#include <iostream>

using namespace std;

int main(void)
{
	double result = 0;
	
	for (unsigned int i = (999 * 999); !result; --i) {
		char *number = uitoa(i);
		
		if (isPalindromic(number)) {
			for (unsigned int factor1 = 999; factor1 > 99; --factor1) {
				double factor2 = (i / factor1);
				
				if (!(i % factor1) && factor2 > 99 && factor2 < 1000) {
					result = i;
					
					break;
				}
			}
		}
	}
	
	cout << "The largest palindrome made from the product of two 3-digit numbers is " << result << '.' << endl;

	return 0;
}
