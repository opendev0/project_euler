/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <iostream>

using namespace std;

int main(void)
{
	int prime = 0, numPrime = 1;
	bool isPrime;
	
	for (unsigned int i = 3; true; i += 2) {
		isPrime = true;
		
		for (unsigned int j = i-1; j > 1; --j) {
			if (!(i % j)) { // If i is divisible by j -> no prime
				isPrime = false;
				break;
			}
		}
		
		if (isPrime) {
			if (++numPrime == 10001) {
				prime = i;
				break;
			}
		}
	}
	
	cout << prime << endl;
	
	return 0;
}
