/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int getAlphabeticalValue(string const &);

int main(void)
{
	ifstream ifs("data/problem22.txt");
	vector<string> names;
	int totalNameScore = 0;
	
	while (ifs.good()) {
		char name[256];
		
		ifs.ignore(1);			// Ignore first quotation mark
		ifs.getline(name, 256, '"');	// Get name and discard last quotation mark
		ifs.ignore(1);			// Ignore comma
		
		names.push_back(name);
	}
	
	ifs.close();
	
	sort(names.begin(), names.end());
	
	for (unsigned int i = 0; i < names.size(); ++i) {
		totalNameScore += (i + 1) * getAlphabeticalValue(names[i]);		
	}
	
	cout << "Total name score: " << totalNameScore << endl;
	
	return 0;
}

unsigned int getAlphabeticalValue(string const & str)
{
	unsigned int value = 0;
	
	for (unsigned int i = 0; i < str.size(); ++i) {
		value += (str[i] - ('A') + 1);
	}
	
	return value;
}