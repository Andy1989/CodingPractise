/*
 * Search a 2D matrix
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *   1.Integers in each row are sorted from left to right.
 *   2.The first integer of each row is greater than the last integer of the previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 1;
        int end = row * col;
        int middle = 0;
        int i = 0;
        int j = 0;
        while(start <= end) {
            middle = (start + end) / 2;
            i = (middle - 1) / col;
            j = (middle - 1) % col;
            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] < target) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }
        return false;
    }
    
};
