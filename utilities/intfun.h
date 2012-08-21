#ifndef __INTFUN_H
#define __INTFUN_H

#include <vector>

unsigned int numDigits(unsigned int number)
{
	unsigned int result = 0;
	
	for (;number > 0; number /= 10, ++result);
	
	return result;
}

unsigned int pow(unsigned int base, unsigned int exp)
{
	unsigned int result = base;
	
	for (unsigned int i = 1; i < exp; ++i, result *= base);
	
	return result;
}

unsigned int factorial(unsigned int n)
{
	unsigned int result = 1;
	
	while (n > 1) {
		result *= n--;
	}
	
	return result;
}

unsigned int sumVector(std::vector<unsigned int> v)
{
	unsigned int result = 0;
	
	for (unsigned int i = 0; i < v.size(); ++i) {
		result += v[i];
	}
	
	return result;
}

std::vector<unsigned int> getDivisors(unsigned int n)
{
	std::vector<unsigned int> divisors;
	divisors.push_back(1);
	
	if (!(n & 1)) {
		divisors.push_back(2);
	}
	
	for (unsigned int i = (n / 2); i > 2; --i) {
		if (!(n % i)) {
			divisors.push_back(i);
		}
	}
	
	return divisors;
}

bool isAbundant(unsigned int n)
{
	if (n < 12) {
		return false;
	}
	
	return (sumVector(getDivisors(n)) > n);
}

unsigned int rotateRight(unsigned int const number)
{
	unsigned int len = numDigits(number);
	
	if (len > 1) {
		unsigned int firstPart = (number % 10) * pow(10, len-1);
		unsigned int lastPart = (number / 10);
		
		return firstPart + lastPart;
	}
		
	return number;
}

unsigned int rotateLeft(unsigned int const number)
{
	unsigned int len = numDigits(number);
	
	if (len > 1) {
		unsigned int power = pow(10, len - 1);
		unsigned int lastPart = (number / power);
		unsigned int firstPart = (number - (lastPart * power)) * 10;
		
		return firstPart + lastPart;
	}
	
	return number;
}

unsigned int squareOfChars(unsigned int i)
{
	unsigned int result = 0;
	
	while (i) {
		result += (i % 10) * (i % 10), i /= 10;
	}
	
	return result;
}

#endif