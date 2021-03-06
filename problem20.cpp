/*
n! means n � (n - 1) � ... � 3 � 2 � 1

For example, 10! = 10 � 9 � ... � 3 � 2 � 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include "utilities/bigint.h"
#include <iostream>

using namespace std;

typedef unsigned int uint;

int main(void)
{
	BigInt bi(100);
	
	for (int i = 99; i; --i) {
		bi *= i;
	}
	
	cout << "The sum of the digits in the number 100! is " << bi.digitSum() << '.' << endl;

	return 0;
}
