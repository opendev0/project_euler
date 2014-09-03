#ifndef __BIGINT_H
#define __BIGINT_H

#include <iostream>    // ostream& operator<<
#include "vector.h"

using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long uint64;

class BigInt
{
public:
    BigInt(){}

	BigInt(BigInt const &bi)
	{
		this->_value = bi._value;
	}

    BigInt(uint number)
	{
		if (number == 0) this->_value.push_back('0');

		while (number) {
			this->_value.push_back((number % 10) + '0');
			number /= 10;
		}
	}

    BigInt(char const *number)
	{
		char const *tmp = number;

		while (*tmp != 0) {
			++tmp;
		}

		while (tmp > number) {
			this->_value.push_back(*(--tmp));
		}
	}

    BigInt &operator=(BigInt const &rhs)
	{
		this->_value = rhs._value;

		return *this;
	}
	
	/* ################ ARITHMETIC OPERATORS ################ */

	BigInt operator+(BigInt const &rhs) const
	{
		BigInt tmp = *this;

		return (tmp += rhs);
	}
	
	BigInt operator+(uint const &rhs) const
	{
		BigInt tmp = *this;

		return (tmp += rhs);
	}
	
	BigInt &operator+=(BigInt const &rhs)
	{
		uchar off = 0;	// overflow-flag
		uchar digit = 0;
		uint op1Size = this->_value.size();
		uint op2Size = rhs._value.size();

		for (uint i = 0; off || i < op1Size || i < op2Size; ++i) {
			if (op1Size == i) {
				this->_value.resize(++op1Size, '0');
			}

			digit = this->_value[i] + off;
			if (op2Size > i) {
				digit += (rhs._value[i] - '0');
			}

			if (digit > BigInt::nine) {
				off = 1;
				digit -= 10;
			} else {
				off = 0;
			}

			this->_value[i] = digit;
		}

		return *this;
	}

    BigInt &operator+=(uint rhs)
	{
		uchar off = 0;	// overflow-flag
		uchar digit = 0;
		uint size = this->_value.size();

		for (uint i = 0; off || rhs || i < size; ++i) {
			if (size == i) {
				this->_value.resize(++size, '0');
			}

			digit = this->_value[i] + (rhs % 10) + off;
			rhs /= 10;

			if (digit > BigInt::nine) {
				off = 1;
				digit -= 10;
			} else {
				off = 0;
			}

			this->_value[i] = digit;
		}

		return *this;
	}
	
	inline BigInt &operator++()
	{
		return (*this += 1);
	}

	inline BigInt operator++(int)
	{
		BigInt tmp = *this;
		++(*this);

		return tmp;
	}
	
	BigInt operator*(BigInt const &rhs) const
	{
		BigInt result = 0U;
		vector<uchar> const *small = ((this->numDigits() <= rhs.numDigits()) ? &this->_value : &rhs._value);
		vector<uchar> const *big = ((this->numDigits() > rhs.numDigits()) ? &this->_value : &rhs._value);
		uint smallSize = small->size();
		uint bigSize = big->size();
		uchar overflow;

		for (uint i = 0; i < smallSize; ++i) {
			BigInt tmp;
			tmp._value.resize(i, '0');
			overflow = 0;

			for (uint j = 0; j < bigSize; ++j) {
				// Can have a maximum value of 89 (9*9+8)
				uchar digit = ((*small)[i] - '0') * ((*big)[j] - '0') + overflow;

				if (digit > 9) {
					overflow = (digit / 10);
					tmp._value.push_back(digit % 10 + '0');
				} else {
					tmp._value.push_back(digit + '0');
					overflow = 0;
				}
			}

			if (overflow > 0) {
				tmp._value.push_back(overflow + '0');
			}

			result += tmp;
		}

		return result;
	}

	inline BigInt &operator*=(BigInt const &rhs)
	{
		*this = *this * rhs;

		return *this;
	}

    BigInt &operator*=(uint const rhs)
	{
		BigInt tmp = *this;

		for (uint i = 1; i < rhs; ++i) {
			*this += tmp;
		}

		return *this;
	}
	
	/* ######################## COMPARISON OPERATORS ################ */
	
	inline bool operator==(BigInt const &rhs) const
	{
		return (this->_value == rhs._value);
	}

	inline bool operator==(uint const rhs) const
	{
		return (BigInt(rhs)._value == this->_value);
	}

	inline bool operator!=(BigInt const &rhs) const
	{
		return !(*this == rhs);
	}

	inline bool operator!=(uint const rhs) const
	{
		return !(*this == rhs);
	}

    bool operator<(BigInt const &rhs) const
	{
		size_t op1Size = this->numDigits();
		size_t op2Size = rhs.numDigits();

		if (op1Size < op2Size) {
			return true;
		} else if (op1Size > op2Size) {
			return false;
		} else {
			do {
				--op1Size;
				
				if (this->_value[op1Size] < rhs._value[op1Size]) {
					return true;
				} else {
					return false;
				}
			} while (op1Size);

			return false;
		}
	}
	
	bool operator>(BigInt const &rhs) const
	{
		size_t op1Size = this->numDigits();
		size_t op2Size = rhs.numDigits();

		if (op1Size > op2Size) {
			return true;
		} else if (op1Size < op2Size) {
			return false;
		} else {
			do {
				--op1Size;
				
				if (this->_value[op1Size] > rhs._value[op1Size]) {
					return true;
				} else {
					return false;
				}
			} while (op1Size);

			return false;
		}
	}
	
	inline bool operator>=(BigInt const &rhs)
	{
		return !(*this < rhs);
	}
	
	inline bool operator<=(BigInt const &rhs)
	{
		return !(*this > rhs);
	}

	inline uint operator[](size_t const i) const
	{
		return (this->_value[this->numDigits() - (1 + i)] - '0');
	}

	/**
	 * @note Changes the object itself rather than returning a new one
	 */
    BigInt &pow(uint const power)
	{
		if (power == 0) {
			this->_value.clear();
			this->_value.push_back('1');
		} else if (power > 1) {
			BigInt tmp(*this);

			for (uint i = 1; i < power; ++i) {
				*this *= tmp;
			}
		}

		return *this;
	}

	inline uint numDigits() const
	{
		return this->_value.size();
	}

    uint digitSum() const
	{
		uint size = this->_value.size();
		uint digitSum = 0;

		for (uint i = 0; i < size; ++i) {
			digitSum += (this->_value[i] - '0');
		}

		return digitSum;
	}

    friend ostream &operator<<(ostream &os, BigInt const &bi)
	{
		unsigned int i = bi.numDigits();

		do {
			os << bi._value[--i];
		} while (i);

		return os;
	}

private:
    static uint const nine = 9 + '0';
    vector<uchar> _value;
};

#endif