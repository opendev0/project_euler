/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <iostream>

using namespace std;

typedef unsigned int uint;

uint atoui(char *str)
{
	uint result = 0;
	char *tmp = str;
	
	while (*(++tmp) != 0);
	
	for (uint i = 1; tmp != str; i *= 10) {
		result += i * (*(--tmp) - '0');
	}
	
	return result;
}

int main(int argc, char **argv)
{
	const uint ones[] = {3, 3, 5, 4, 4, 3, 5, 5, 4};		// {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}
	const uint specialTens[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};	// {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}
	const uint tens[] = {6, 6, 5, 5, 5, 7, 6, 6};			// {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}
	uint min, max, result = 0;
	
	if (argc == 2) {
		min = max = atoui(argv[1]);
	} else if (argc == 3) {
		min = atoui(argv[1]);
		max = atoui(argv[2]);
	} else {
		cout << "Usage:" << endl << '\t' << argv[0] << " number" << endl << "\tor" << endl << '\t' << argv[0] << " startnumber endnumber" << endl;
		
		return 1;
	}
	
	cout << "min: " << min << endl << "max: " << max << endl << endl;
	
	for (uint i = min; i <= max; ++i) {
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
	
	cout << "Result: " << result << endl;
	
	return 0;
}
