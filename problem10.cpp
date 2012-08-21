/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <iostream>

using namespace std;

int main(void)
{
	unsigned long long result = 0;

	const int limit = 2000000;

	bool *prime = new bool[limit];

	for (int i = 2; i < limit; ++i) {
		prime[i] = true;
	}

	for (int i = 2; i < limit; ++i) {
		if (prime[i]) {
			result += i;
			for (int j = i+i; j < limit; j += i) {
				prime[j] = false;
			}
		}
	}

	cout << result << endl;
	
	return 0;
}
