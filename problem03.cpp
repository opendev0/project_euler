/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>

using namespace std;

bool isPrime(unsigned int);

int main(void)
{
	unsigned long long number = 600851475143;
	unsigned int i = 2;
	
	for (; number > 1; ++i) {
		if (isPrime(i)) {
			if (!(number % i)) {
				number /= i;
			}
		}
	}
	
	cout << "Biggest prime factor: " << --i << endl;
	
	return 0;
}

bool isPrime(unsigned int n)
{
	if (n == 0 || n == 1) return false;
	
	// If n is evenly divisible by a number less than itself and greater than 1 -> no prime
	for (unsigned int i = (n - 1); i >= 2; --i) {
		if (!(n % i)) {
			return false;
		}
	}
	
	return true;
}
