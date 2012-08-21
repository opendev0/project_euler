#ifndef __STRFUN_H
#define __STRFUN_H

#include <string>

int strlen(char const *str)
{
	int len = 0;
	
	while (*(str++) != 0) {
		++len;
	}
	
	return len;
}

/*
unsigned int strlen(const char * const str)
{
	const char *tmp = str;
	
	while (*(++tmp) != 0);
	
	return ((tmp - str) / sizeof(char));
}
*/

unsigned int strToUInt(char const *str)
{
	unsigned int result = 0;
	
	for (; *str >= '0' && *str <= '9'; ++str) {
		result = (result * 10) + (*str - '0');
	}
	
	return result;
}

char *invert(const char *str)
{
	unsigned int len = strlen(str);
	
	char *result = new char[len + 1];
	result[len] = '\0';
	
	for (int i = len-1; i >= 0; --i, ++str) {
		result[i] = *str;
	}
	
	return result;
}

/*char *invert(const char *str)
{
	const unsigned int len = strlen(str);
	char *result = new char[len + 1];
	
	for (unsigned int i = 0; i < len; ++i) {
		result[i] = str[len - (i + 1)];
	}
	
	result[len] = 0;
	
	return result;
}*/

char *uitoa(unsigned int n)
{
	std::string result;
	
	while (n > 0) {
		result += (n % 10) + '0';
		n /= 10;
	}
	
	return invert(result.c_str());
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != 0 && *str2 != 0) {
		if (*str1 == *str2) {
			++str1;
			++str2;
			continue;
		} else if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		}
		
		++str1;
		++str2;
	}
	
	unsigned int len1 = strlen(str1);
	unsigned int len2 = strlen(str2);
	
	if (len1 < len2)
		return -1;
	else if (len1 > len2)
		return 1;
	else
		return 0;
}

bool isPalindromic(const char *str)
{
	for (unsigned int i = 0, j = (strlen(str) - 1); i < j; ++i, --j) {
		if (str[i] != str[j]) {
			return false;
		}
	}
	
	return true;
}

char *dec2bin(unsigned int n)
{
	std::string result;
	
	while (n > 0) {
		result += (n % 2) + '0';
		n /= 2;
	}
	
	return invert(result.c_str());
}

#endif