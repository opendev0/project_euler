#ifndef __PRIMES_H
#define __PRIMES_H

#include <vector>
#include <set>
#include "intfun.h"

using namespace std;


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

vector<unsigned int> getPrimes(unsigned int upperLimit)
{
	++upperLimit;
	vector<unsigned int> primes;
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
			
			primes.push_back(i);
		}
	}
	
	delete numbers;
	
	return primes;
}

set<unsigned int> getPrimesAsSet(unsigned int upperLimit)
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

bool isTruncateable(unsigned int const n, set<unsigned int> const &primes)
{
	unsigned int len = numDigits(n);
	unsigned int copy = n;
	
	if (len == 1) return false;
	
	// Trim from right to left
	for (unsigned int i = 1; i < len; ++i) {
		copy /= 10;
		
		if (primes.find(copy) == primes.end()) {
			return false;
		}
	}
	
	copy = n;
	// Trim from left to right
	for (unsigned int j = len; j > 0; --j) {
		unsigned int power = pow(10, j-1);
		copy -= (copy / power) * power;
		
		if (primes.find(copy) == primes.end()) {
			return false;
		}
	}
	
	return true;
}

#endif
