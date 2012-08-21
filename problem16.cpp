/*
215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^(1000)?
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int main(void)
{
	double power = pow(2, 1000);
	unsigned int result = 0;
	
	ostringstream out;
	out << setprecision(512) << power;
	
	for (unsigned int i = 0; i < out.str().length(); ++i) {
		result += (out.str()[i] - '0');
	}
	
	cout << result << endl;

	return 0;
}
