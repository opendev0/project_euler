/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include <iostream>

using namespace std;

int main(void)
{
	unsigned int result = 1, up = 1, down = 1;
	
	for (unsigned int i = 1, j = 1; j < 1001; ++i, j += 2) {
		down += 4 * i;
		result += down;
		
		down += 4 * i;
		result += down;
		
		up += (4 * i) - 2;
		result += up;
		
		up += 4 * i;
		result += up;
	}
	
	cout << "The sum of the numbers on the diagonals in a 1001 by 1001 spiral is " << result << '.' << endl;
	
	return 0;
}
