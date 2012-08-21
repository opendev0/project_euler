/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>

using namespace std;

int main(void)
{
	bool divisible = false;
	const unsigned int max = 20;

	unsigned int i = max;
	for (; !divisible; i += max) {
		divisible = true;

		for (unsigned int j = 1; j <= max; ++j) {
			if (i % j) {
				divisible = false;
				break;
			}
		}
	}

	cout << (i - max) << endl;
	
	return 0;
}
