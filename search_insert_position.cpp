/*
 * Search Insert Position
 *
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0, end = n - 1, middle;
        if(n == 0) {
            return 0;
        }
        while(start <= end) {
            middle = (start + end) / 2;
            if(A[middle] > target) {
                end = middle - 1;
            } else if(A[middle] == target) {
                return middle;
            } else {
                start = middle + 1;
            }
        }
        if(start >= n && A[n - 1] < target) {
            return n;
        } else if(end < 0 && A[0] > target) {
            return 0;
        } else if(A[start] > target && A[end] < target && start - end == 1) {
            return start;
        }
    }
};
