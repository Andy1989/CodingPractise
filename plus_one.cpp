/* Plus One
 * Given a number represented as an array of digits, plus one to the number.
 *
 */
 
#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int> &digits) {
	if(digits.size() == 0) {
		digits.push_back(1);
	} else {
		unsigned int i = digits.size();
		unsigned int value = digits.at(i - 1) + 1;
		unsigned int C = value > 9 ? 1 : 0;
		vector<int>::iterator it;
		digits.at(i - 1) = value % 10;
		i--;
		while(C && i > 0) {
			value = digits.at(i - 1) + C;
			C = value > 9 ? 1 : 0;
			digits.at(i - 1) = value % 10;
			i--;
		}
		if(C) {
			it = digits.begin();
			digits.insert(it, C);
		}
	}
	return digits;
}

int main() {
	vector<int> digits(3, 9);
	digits = plusOne(digits);
	
	for(vector<int>::iterator it = digits.begin();
	it < digits.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}

