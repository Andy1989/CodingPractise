/*
 * Implement atoi to convert a string to an integer.
 * Hint: Carefully consider all possible input cases. 
 * If you want a challenge, please do not see below 
 * and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified 
 * vaguely (ie, no given input specs). You are responsible 
 * to gather all the input requirements up front.
 */
class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char *head = (char*)str;
        int length = 0;
        unsigned long int num = 0;
        int rv;
        int i,base,sign;
        // Find the head of number 
        while(*head != '\0') { 
            if(*head - '0' <= 9 && *head - '0' >= 0){
                break;
            }
            head++;
        }
        if(*head == '\0') // No number to convert in the given string
            return 0;
        // Determine how many digits the number has     
        for(i = 1; *(head + i) - '0' <= 9 && *(head + i) - '0' >= 0; i++);
        length = i;
        
        char *end = head + length - 1;
        if(length >10) {
            num = 2147483648;
        } else {
            for(base = 1; end != head; end--) {
                num += (*end - '0') * base;
                base *= 10;
                if(num > 2147483648)
                    break;
            }
            if(end == head) {
                num += (*end - '0') * base;
            }
        }
        // check sign and other invalid format
        if(head != str) {
            head--;
            if(*head == '-') {
                head--;
                if(*head == '-' || *head == '+') // e.g. "--123", "+-123"
                    rv = 0;
                else {
                    if(num > 2147483648)
                        rv = -2147483648;
                    else
                        rv = 0 - num;
                }
            } else if(*head == '+'){
                head--;
                if(*head == '-' || *head == '+') { // e.g. invalid format: "++123", "-+123"
                    rv = 0;
                } else {
                    if(num >2147483647)
                        rv = 2147483647;
                    else                      // e.g. valid format: "+123"
                        rv = num;
                }
                
            } else if(*head != ' ') { // e.g. "b1234"
                rv = 0;
            } else {
                while(*head != '-' && *head != '+' && head != str)
                    head--;
                if(*head == '-' || *head == '+') // e.g. " - 123", "+ 123"
                    rv = 0;
                else {
                    if(num >2147483647)
                        rv = 2147483647;
                    else
                        rv = num;
                }
            }
            
        } else {
            if(num <= 2147483647)
                rv = num;
            else
                rv = 2147483647;
        }
        
        return rv;
    }
};
