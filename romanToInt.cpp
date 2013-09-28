/**
 * Roman to Integer 
 * 
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unsigned int len = s.size();
        unsigned int sum = 0, i = 0, cur = 0, prev = 0;
        if(len == 0) {
            return 0;
        }
        sum = getInt(s.at(i++));
        while(i < len) {
            cur = getInt(s.at(i));
            prev = getInt(s.at(i - 1));
            if(prev < cur) {
                sum += cur - 2 * prev;
            } else {
                sum += cur;
            }
            i++;
        }
        return sum;
    }
    int getInt(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default : return -1;
        }
    }
};
