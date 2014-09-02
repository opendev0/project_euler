/*
The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^(6972593)-1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2^(p)-1, have been found which contain more digits.

However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×2^(7830457)+1.

Find the last ten digits of this prime number.
*/

#include <iostream>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long uint64;

uint64 pow(uint x, uint y)
{
	uint64 result = x;
	
	for (uint i = 1; i < y; ++i) {
		result *= x;
		result %= 10000000000;
	}
	
	return result;
}

int main(void)
{	
	cout << "The last ten digits of the non-Mersenne prime 28433*2^(7830457)+1 is " << (((28433 * pow(2, 7830457)) + 1) % 10000000000) << '.' << endl;

	return 0;
}
