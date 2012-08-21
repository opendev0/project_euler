/*
A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?
*/

#include "utilities/intfun.h"
#include <iostream>

using namespace std;

int main(void)
{
	unsigned int counter = 0;
	
	for (unsigned int i = 2; i < 10000000; ++i) {
		unsigned int j = i;
		
		do {
			j = squareOfChars(j);
			
			if (j == 89) {
				++counter;
				break;
			}
		} while (j != 1);
	}
	
	cout << counter << endl;
}
