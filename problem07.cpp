/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include "utilities/primes.h"
#include <iostream>

using namespace std;

int main(void)
{
	unsigned int prime = 0, numPrime = 1;
	
	for (unsigned int i = 3; true; i += 2) {
		if (isPrime(i)) {
			if (++numPrime == 10001) {
				prime = i;
				break;
			}
		}
	}
	
	cout << "The 10001st prime number is " << prime << '.' << endl;
	
	return 0;
}
