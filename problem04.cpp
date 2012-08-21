/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include "utilities/strfun.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{	
	for (int i = 999*999; i; --i) {
		ostringstream out;
		out << i;
		
		const char *str = out.str().c_str();
		
		if (!strcmp(str, strinv(str))) {			
			for (unsigned int j = 999; j > 99; --j) {
				double result = (i / j);
				if (!(i % j) && result > 99 && result < 1000) {
					cout << i << " (" << j << " * " << result << ')' << endl;
					
					return 0;
				}
			}
		}
	}

	return 0;
}
