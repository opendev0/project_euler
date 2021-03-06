/*
Consider all integer combinations of a^b for 2 <= a <= 5 and 2 <= b <= 5:

    2^2=4, 2^3=8, 2^4=16, 2^5=32
    3^2=9, 3^3=27, 3^4=81, 3^5=243
    4^2=16, 4^3=64, 4^4=256, 4^5=1024
    5^2=25, 5^3=125, 5^4=625, 5^5=3125

If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:

4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

How many distinct terms are in the sequence generated by a^b for 2 <= a <= 100 and 2 <= b <= 100?

*/

#include "utilities/bigint.h"
#include <iostream>
#include "utilities/vector.h"

using namespace std;

typedef unsigned int uint;

int main(void)
{
	//set<BigInt> results;
	vector<BigInt> results;
	bool found;
	
	for (uint i = 2; i < 101; ++i) {
		for (uint j = 2; j < 101; ++j) {
			found = false;
			BigInt bi = BigInt(i).pow(j);
			
			for (uint k = 0; k < results.size(); ++k) {
				if (results[k] == bi) found = true;
			}
			
			if (!found) results.push_back(bi);
		}
	}
	
	cout << "The number of distinct terms in the sequence generated by a^b for 2 <= a <= 100 and 2 <= b <= 100 is " << results.size() << '.' << endl;

	return 0;
}
