/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <iostream>
#include <unordered_set>
#include "utilities/intfun.h"

using namespace std;

typedef unsigned int uint;

int main(void)
{
	unordered_set<uint> resultSet;
	vector<uint> numbers;
	const uint max = 28124;
	bool abundant[max] = {false};
	uint result = 0;
	
	for (uint i = 1; i < max; ++i) {
		resultSet.insert(i);
	}
	
	for (uint i = 12; i < max; ++i) {
		if (isAbundant(i)) {
			abundant[i] = true;
		}
	}
	
	for (uint i = 12; i < max; ++i) {
		if (abundant[i]) {
			for (uint j = i; j < max; ++j) {
				if (abundant[j]) {
					resultSet.erase(i + j);
				}
			}
		}
	}
	
	for (unordered_set<uint>::iterator it = resultSet.begin(); it != resultSet.end(); ++it) {
		result += *it;
	}
	
	cout << "The sum of all positive integers which cannot be written as the sum of two abundant numbers is " << result << '.' << endl;
}
