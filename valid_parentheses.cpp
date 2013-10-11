/**
 * Valid Parentheses 
 * 
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid 
 * but "(]" and "([)]" are not.
 */
class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<string> mystack;
        string ch;
        unsigned int len = s.length();
        if(len & 1 == 1 || len == 0) {
            return false;
        }
        if(s.at(0) == ')' || s.at(0) == '}' || s.at(0) == ']') 
            return false;
        for(unsigned int i = 0; i < len; i++) {
            if(s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') {
                ch.assign(s, i, 1);
                mystack.push(ch);
            } else if(s.at(i) == ')') {
                ch.assign(mystack.top());
                if(ch.at(0) != '(') {
                    return false;
                }
                mystack.pop();
            } else if(s.at(i) == '}') {
                ch.assign(mystack.top());
                if(ch.at(0) != '{') {
                    return false;
                }
                mystack.pop();
            } else if(s.at(i) == ']') {
                ch.assign(mystack.top());
                if(ch.at(0) != '[') {
                    return false;
                }
                mystack.pop();
            }
        }
        return mystack.empty();
    }
};
