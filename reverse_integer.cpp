/**
 * Reverse Integer
 * 
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 *
 * Example2: x = -123, return -321
 */
class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int digits[10] = {0}, i = 0;
        int sign = (x >= 0) ? 1 : -1;
        int base = 1;
        x = abs(x);
        if(x == 0)  return 0;
        while(x > 0) {
            digits[i++] = x % 10;
            x /= 10;
        }
        while(i > 0) {
            x += digits[--i] * base;
            base *= 10;
        }
        x *= sign;
        return x;
    }
};
