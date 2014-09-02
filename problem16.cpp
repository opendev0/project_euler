/*
215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^(1000)?
*/

#include "utilities/bigint.h"
#include <iostream>

using namespace std;

int main(void)
{
	BigInt bi(2);
	bi.pow(1000);
	
	cout << "The sum of the digits of 2^1000 is " << bi.digitSum() << '.' << endl;

	return 0;
}
