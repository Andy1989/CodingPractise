/*
 * Climbing Stairs
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 * Algorithm:
 * 1. Recursion
 * 2. Assuming f(n) represents the number of distinct ways to the n-th step, then
 * f(n) = f(n - 1) + f(n - 2)
 * 3. Base cases: f(1) = 1, f(2) = 2
 */
 
class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // What should be returned if n <= 0?
        int p, p_1, p_2, i, target;
        if(n == 0) {
            return 0;
        } else if(n == 1) {
            return 1;
        } else if(n == 2) {
            return 2;
        } else {
            for(p_1 = 2, p_2 = 1, i = 3; i <= n; i++) {
                p = p_1 + p_2;
                target = p;
                p_2 = p_1;
                p_1 = p;
            }
            return target;
            //return climbStairs(n - 1) + climbStairs(n - 2) * 2;
        }
    }
};
