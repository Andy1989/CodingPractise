/**
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on 
 * the row below.
 * 
 * For example, given the following triangle
 * [
 *    [2],
 *   [3,4],
 *  [6,5,7],
 * [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * Notes:
 * Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows 
 * in the triangle.
 **/
 // Solution 1: Time limit exceeded
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return minimumSub(triangle, 0, 0);
    }
    int minimumSub(vector<vector<int>> &triangle, 
                vector<vector<int>>::size_type depth,
                vector<int>::size_type i){
        if(depth != triangle.size()){
            return triangle[depth][i] + min(minimumSub(triangle, depth+1,i), minimumSub(triangle, depth+1, i+1));
        } else{
            return 0;
        }
    }
};
