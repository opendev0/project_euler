/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include "utilities/primes.h"
#include <iostream>

using namespace std;

int main(void)
{
	vector<unsigned int> primeFactors = getPrimeFactors(600851475143);
	
	cout << "Largest prime factor: " << primeFactors.back() << endl;
	
	return 0;
}
