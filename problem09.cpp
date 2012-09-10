/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 32 + 42 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>

using namespace std;

int main(void)
{
	unsigned int result = 0;
	
	for (unsigned int a = 1; (a < 1000 && !result); ++a) {
		for (unsigned int b = (a + 1); (b < 1000 && !result); ++b) {
			for (unsigned int c = (b + 1); c < 1000; ++c) {
				if (((a + b + c) == 1000) && ((a * a) + (b * b) == (c * c))) {
					result = (a * b * c);

					break;
				}
			}
		}
	}
	
	cout << "The product of the Pythagorean triplet for which a + b + c = 1000 is " << result << '.';

	return 0;
}
