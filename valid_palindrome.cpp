/*
 * Valid Palindrome
 * 
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * 
 * For the purpose of this problem, we define empty string as valid palindrome.
 */
class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unsigned int len = s.length();
        unsigned int i = 0, j = len - 1;
        if(len < 2) {
            return true;
        }
        while(i < j) {
            if(!isalnum(s.at(i))) {
                i++;
                continue;
            } else if(!isalnum(s.at(j))) {
                j--;
                continue;
            } else if(tolower(s.at(i)) == tolower(s.at(j))) {
                i++;
                j--;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};
