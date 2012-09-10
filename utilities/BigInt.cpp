#include "BigInt.h"

BigInt::BigInt(){}

BigInt::BigInt(BigInt const & bi)
{
	this->_value = bi._value;
}

BigInt::BigInt(uint number)
{	
	while (number) {
		this->_value.push_back((number % 10) + '0');
		number /= 10;
	}
}

BigInt::BigInt(char const *number)
{	
	char const *tmp = number;

	while (*tmp != 0) {
		++tmp;
	}

	while (tmp > number) {
		this->_value.push_back(*(--tmp));
	}
}

BigInt& BigInt::operator=(BigInt const &bi)
{	
	this->_value = bi._value;

	return *this;
}

BigInt& BigInt::operator+=(BigInt const &bi)
{
	uchar	off = 0,    // overflow-flag
			digit = 0;
	uint   	op1Size = this->_value.size(),
			op2Size = bi._value.size();

	for (uint i = 0; off || i < op1Size || i < op2Size; ++i) {
		if (op1Size == i) {
			this->_value.resize(++op1Size, '0');
		}
	
		digit = this->_value[i] + off;
		if (op2Size > i) {
			digit += (bi._value[i] - '0');
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

BigInt& BigInt::operator+=(uint number)
{
	uchar  	off = 0,    // overflow-flag
			digit = 0;
	uint	size = this->_value.size();

	for (uint i = 0; off || number || i < size; ++i) {
		if (size == i) {
			this->_value.resize(++size, '0');
		}

		digit = this->_value[i] + (number % 10) + off;
		number /= 10;

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

BigInt& BigInt::operator+(BigInt const &bi) const
{
	BigInt *tmp = new BigInt(*this);
	
	return (*tmp += bi);
}

BigInt& BigInt::operator*=(BigInt const &bi)
{
	const vector<uchar> *small = ((this->_value.size() <= bi._value.size()) ? &this->_value : &bi._value);
	const vector<uchar> *big = ((this->_value.size() > bi._value.size()) ? &this->_value : &bi._value);
	uint smallSize = small->size();
	uint bigSize = big->size();
	uchar overflow;

	vector<BigInt> values;

	for (uint i = 0; i < smallSize; ++i) {
		BigInt tmp;
		tmp._value.resize(i, '0');    // push zeros
		overflow = 0;
	
		for (uint j = 0; j < bigSize; ++j) {
			uint digit = static_cast<uchar>((small->operator[](i) - '0') * (big->operator[](j) - '0') + overflow);

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
	
		values.push_back(tmp);
	}

	this->_value.clear();

	for (uint i = 0; i < values.size(); ++i) {
		*this += values[i];
	}

	return *this;
}

BigInt& BigInt::operator*=(uint number)
{
	BigInt tmp(*this);
	--number;

	for (uint i = 0; i < number; ++i) {
		*this += tmp;
	}

	return *this;
}

BigInt& BigInt::operator++()
{
	return (*this += 1);
}

bool BigInt::operator<(BigInt const &bi) const
{
	uint op1Size = this->_value.size();
	uint op2Size = bi._value.size();

	if (op1Size < op2Size) {
		return true;
	} else if (op1Size > op2Size) {
		return false;
	} else {
		for (int i = (op1Size - 1); i >= 0; --i) {
			if (this->_value[i] < bi._value[i]) {
				return true;
			}
		}

		return false;
	}
}

bool BigInt::operator==(BigInt const &bi) const
{
	return (this->_value == bi._value);
}

bool BigInt::operator==(uint const n) const
{
	return (BigInt(n)._value == this->_value);
}

uint BigInt::operator[](uint const i) const
{
	return (this->_value[i] - '0');
}

BigInt& BigInt::pow(uint power)
{
	if (!power) return *(new BigInt(1));

	BigInt tmp(*this);

	while (--power) {
		*this *= tmp;
	}

	return *this;
}

uint BigInt::digitSum() const
{
	uint size = this->_value.size();
	uint digitSum = 0;

	for (uint i = 0; i < size; ++i) {
		digitSum += (this->_value[i] - '0');
	}

	return digitSum;
}

ostream& operator<<(ostream& os, BigInt const &bi)
{
	return os << string(bi._value.rbegin(), bi._value.rend());
}
