#ifndef __PRIMES_H
#define __PRIMES_H

#include <cmath>	// sqrt
#include <set>		// TODO: Get rid of it
#include "intfun.h"
#include "vector.h"

using namespace std;


bool isPrime(unsigned int n)
{
	if (n == 2) return true;
	if (!(n & 1) || n <= 1) return false;
	
	unsigned int maxDivisor = sqrt(n);
	
	for (unsigned int i = 3; i <= maxDivisor; i += 2) {
		if (!(n % i)) {
			return false;
		}
	}
	
	return true;
}

bool isPrime(int n)
{
	if (!(n & 1) || n <= 1) return false;
	
	unsigned int maxDivisor = sqrt(n);
	
	for (unsigned int i = 3; i <= maxDivisor; i += 2) {
		if (!(n % i)) {
			return false;
		}
	}
	
	return true;
}

set<unsigned int> getPrimes(unsigned int upperLimit)
{
	++upperLimit;
	set<unsigned int> primes;
	bool * const numbers = new bool[upperLimit];
	
	numbers[0] = numbers[1] = false;
	
	for (unsigned int i = 2; i < upperLimit; ++i) {
		numbers[i] = true;
	}
	
	for (unsigned int i = 2; i < upperLimit; ++i) {
		if (numbers[i]) {
			for (unsigned int j = i; j < upperLimit; j += i) {
				numbers[j] = false;
			}
			
			primes.insert(i);
		}
	}
	
	delete numbers;
	
	return primes;
}

vector<unsigned int> getPrimeFactors(unsigned long long n)
{
	vector<unsigned int> factors;
	
	for (unsigned int i = 2; n > 1; ++i) {
		if (isPrime(i)) {
			if (!(n % i)) {
				n /= i;
				factors.push_back(i);
			}
		}
	}
	
	return factors;
}

vector<unsigned int> getCircularPrimes(set<unsigned int> const &primeSet)
{
	vector<unsigned int> result;
	
	for (set<unsigned int>::iterator it = primeSet.begin(); it != primeSet.end(); ++it) {
		unsigned int curPrime = *it;
		
		do {
			curPrime = rotateRight(curPrime);
			
			if (primeSet.find(curPrime) == primeSet.end()) {
				break;
			}
		} while (curPrime != *it);
		
		if (curPrime == *it) {
			result.push_back(*it);
		}
	}
	
	return result;
}

/**
 * Truncatable primes are prime numbers that remain prime if you remove digits from the left or right.
 */
bool isTruncateablePrime(unsigned int const n)
{	
	unsigned int len = numDigits(n);
	unsigned int copy = n;
	
	if (len == 1) return false;
	
	// Trim from right to left
	for (unsigned int i = 1; i < len; ++i) {
		copy /= 10;
		
		if (!isPrime(copy)) {
			return false;
		}
	}
	
	copy = n;
	// Trim from left to right
	for (unsigned int i = len - 1; i > 0; --i) {
		unsigned int power = pow(10, i);
		copy -= (copy / power) * power;
		
		if (!isPrime(copy)) {
			return false;
		}
	}
	
	return true;
}

#endif
