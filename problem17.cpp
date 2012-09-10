/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include "utilities/strfun.h"
#include <iostream>

using namespace std;

typedef unsigned int uint;

int main(int argc, char **argv)
{
	uint const ones[] = {3, 3, 5, 4, 4, 3, 5, 5, 4};			// {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}
	uint const specialTens[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};	// {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}
	uint const tens[] = {6, 6, 5, 5, 5, 7, 6, 6};				// {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}
	unsigned int result = 0;
		
	for (uint i = 1; i <= 1000; ++i) {
		uint j = i;
		
		if (j > 999 && j < 10000) {
			result += ones[(j / 1000) - 1];
			result += 8;					// "thousand"
			
			j %= 1000;
		}
		
		if (j > 99 && j < 1000) {
			result += ones[(j / 100) - 1];
			result += 7;					// "hundred"
			j %= 100;
			
			if (j) {
				result += 3;				// "and"
			}
		}
		
		if (j > 9 && j < 100) {
			if (j < 20) {
				result += specialTens[j % 10];
			} else {
				result += tens[(j / 10) - 2];
				j %= 10;
			}
		}
		
		if (j && j < 10) {
			result += ones[j - 1];
		}
	}
	
	cout << "The number of letters of all written out words from 1 to 1000 is " << result << '.' << endl;
	
	return 0;
}
