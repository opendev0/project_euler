/*
The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

Find the last ten digits of the series, 1^(1) + 2^(2) + 3^(3) + ... + 1000^(1000).
*/

#include "utilities/vector.h"
#include "utilities/bigint.h"
#include <future>

using namespace std;

BigInt& selfpow(int i)
{
	BigInt *result = new BigInt();
	uint max = i + 50;

	cout << "Thread started with " << i << endl;
	for (uint min = i; min < max; ++min) {
		*result += BigInt(min).pow(min);
	}

	cout << "Thread ended with " << (max-1) << endl;

	return *result;
}

int main(void)
{
	BigInt bi(1);
	
	vector<future<BigInt&>> threads;

	for (uint i = 2; i < 101; ++i) {
		bi += BigInt(i).pow(i);
	}

	for (uint i = 101; i < 1001; i += 50) {
		threads.push_back(async(launch::async, selfpow, i));
	}

	for (uint i = 0; i < threads.size(); ++i) {
		bi += threads[i].get();
	}

	cout << "The result of the series 1^1 + 2^2 + ... + 1000^1000 is " << bi << '.' << endl;

	return 0;
}
