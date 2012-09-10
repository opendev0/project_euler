/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include "utilities/primes.h"
#include <iostream>

using namespace std;

int main(void)
{
	set<unsigned int> primes = getPrimes(1999999);
	unsigned long long result = 0;
	
	for (set<unsigned int>::iterator it = primes.begin(); it != primes.end(); ++it) {
		result += *it;
	}

	cout << "The sum of all primes below two million is " << result << '.' << endl;
	
	return 0;
}
