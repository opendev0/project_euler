/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/

#include "utilities/primes.h"
#include <iostream>
#include <set>

using namespace std;


int main(int argc, char **argv)
{	
	set<unsigned int> const primes = getPrimesAsSet(1000000);
	
	cout << getCircularPrimes(primes).size() << endl;
	
	return 0;
}