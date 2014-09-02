/*
Euler discovered the remarkable quadratic formula:

n^2 + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n^2 − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n^2 + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/

#include <iostream>
#include <cmath>
#include "utilities/primes.h"

using namespace std;

unsigned int numberOfConsecutivePrimes(int a, int b)
{
	for (unsigned int i = 0; true; ++i) {
		int result = i * (i + a) + b;
		
		if (!isPrime(result)) {
			return i;
		}
	}
}

int main(void)
{
	int aMax = 0;
	int bMax = 0;
	unsigned int maxPrimes = 0;
	
	for (int i = -1000; i <= 1000; ++i) {
		for (int j = -1000; j <= 1000; ++j) {
			unsigned int consecutivePrimes = numberOfConsecutivePrimes(i, j);
			if (consecutivePrimes > maxPrimes) {
				aMax = i;
				bMax = j;
				maxPrimes = consecutivePrimes;
			}
		}
	}
	cout << "n^2 + an + b produces maximum number of consecutive primes with |a| < 1000, |b| < 1000 for a*b: " << aMax * bMax << endl;	

	return 0;
}