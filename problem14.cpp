/*
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>

using namespace std;

int main(void)
{
	unsigned long long highest = 0, startingNumber = 0, chainLength;
	
	for (unsigned long long i = 2; i < 1000000; ++i) {
		chainLength = 0;
		
		for (unsigned long long j = i; j > 1; ++chainLength) {
			if (j & 1) {
				j = 3 * j + 1;
			} else {
				j /= 2;
			}
		}
		
		if (chainLength > highest) {
			highest = chainLength;
			startingNumber = i;
		}
	}
	
	cout << "The starting number which produces the longest chain is " << startingNumber << '.' << endl;

	return 0;
}
