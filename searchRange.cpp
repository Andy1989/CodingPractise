/*
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> myvector (2);
        myvector[0] = -1;
        myvector[1] = -1;
        if(n == 0) {
            return myvector;
        }
        // Find target
        int start = 0;
        int end = n - 1;
        int middle = (start + end) / 2;
        while(A[middle] != target && start <= end) {
            if(A[middle] < target) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
            middle = (start + end) / 2;
        }
        
        if(A[middle] == target) {
            myvector[0] = middle;
            myvector[1] = middle;
            // Find start
            start = 0;
            end = middle;
            middle = (start + end) / 2;
            while(start < end) {
                if(A[middle] == target) {
                    myvector[0] = middle;
                    end = middle - 1;
                } else  {
                    start = middle + 1;
                }
                middle = (start + end) / 2;
            }
            if(A[start] == target) {
                myvector[0] = start;
            }
            
            // Find end    
            start = middle;
            end = n - 1;
            middle = (start + end) / 2;
            while(start < end) {
                if(A[middle] == target) {
                    myvector[1] = middle;
                    start = middle + 1;
                } else {
                    end = middle - 1;
                }
                middle = (start + end) / 2;
            }
            if(A[start] == target) {
                myvector[1] = start;
            }
                
            
        } 
        return myvector;
    }
};
