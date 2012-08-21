#ifndef __BIGINT_H
#define __BIGINT_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef	unsigned int		uint;
typedef	unsigned char		uchar;
typedef	unsigned long long	uint64;

class BigInt
{
public:
	static const uint nine = 9 + '0';
	vector<uchar> _value;

public:
	BigInt();
	BigInt(BigInt const &);
	explicit BigInt(uint);
	explicit BigInt(char const *);
	
	BigInt& operator=(BigInt const &);
	BigInt& operator+=(BigInt const &);
	BigInt& operator+=(uint);
	BigInt& operator+(BigInt const &) const;
	BigInt& operator*=(BigInt const &);
	BigInt& operator*=(uint);
	BigInt& operator++();
	
	bool operator<(BigInt const &) const;
	bool operator==(BigInt const &) const;
	bool operator==(uint const) const;
	
	uint operator[](uint const) const;
	
	inline vector<uchar> const value() const { return this->_value; };
	BigInt& pow(uint);
	uint digitSum() const;
	inline uint numDigits() const { return this->_value.size(); };

	friend ostream& operator<<(ostream&, BigInt const &);
};

#endif
