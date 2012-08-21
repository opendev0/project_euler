/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>

using namespace std;

int main(void)
{
	const unsigned long long number = 600851475143;
	bool primeFactor;

	for (unsigned long long i = (number / 2); i > 2; --i) {
		primeFactor = true;

		if (!(number % i)) {
			for (unsigned long long j = ((i / 2) - 1); j > 1; --j) {
				// If number is evenly divisible by a number smaller than itself and bigger than 1 -> no prime
				if (!(i % j)) {
					primeFactor = false;
					break;
				}
			}
			
			if (primeFactor && !(number % i)) {
				cout << i << endl;
				break;
			}
		}
	}
	
	return 0;
}
