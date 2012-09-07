/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include "utilities/primes.h"
#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	unsigned int result = 0;
	
	set<unsigned int> const primes = getPrimes(1000000);
	
	for (set<unsigned int>::iterator it = primes.begin(); it != primes.end(); ++it) {
		if (isTruncateable(*it, primes)) {
			result += *it;
		}
	}
	
	cout << "Result: " << result << endl;
	
	return 0;
}
