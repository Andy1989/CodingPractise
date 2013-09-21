/* Spiral Matrix 
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * 
 * For example,
 * Given the following matrix:
 * 
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
    	// Start typing your C/C++ solution below
    	// DO NOT write int main() function
    	vector<int> rv;
    	if(matrix.size() == 0) {
    	    return rv;
    	}
    	if(matrix.at(0).size() == 0) {
    	    return rv;
    	}
    	unsigned int row = matrix.size();
    	unsigned int col = matrix.at(0).size();
    	unsigned total = row * col;
    	
    	if(row > 0) {
    		
    		if(col > 0) {
    			
    			unsigned int row_lower_bound = 0;
    			unsigned int row_upper_bound = row - 1;
    			unsigned int col_lower_bound = 0;
    			unsigned int col_upper_bound = col - 1;
    			int temp = 0;
    			for(unsigned int i = row_lower_bound, j = col_lower_bound, num = 0;
    			num < total;
    			i = row_lower_bound, j = col_lower_bound) {
    				if(row_lower_bound == row_upper_bound) {
    					while(j <= col_upper_bound) {
    						temp = matrix.at(i).at(j);
    						rv.push_back(temp);
    						num++;
    						j++;
    					}
    					continue;
    				}
    				
    				if(col_lower_bound == col_upper_bound) {
    					while(i <= row_upper_bound) {
    						temp = matrix.at(i).at(j);
    						rv.push_back(temp);
    						num++;
    						i++;
    					}
    					continue;
    				}
    				while(j < col_upper_bound) {
    					temp = matrix.at(i).at(j);
    					rv.push_back(temp);
    					num++;
    					j++;
    				}
    
    				while(i < row_upper_bound) {
    					temp = matrix.at(i).at(j);
    					rv.push_back(temp);
    					num++;
    					i++;
    				}
    				
    				while(j > col_lower_bound) {
    					temp = matrix.at(i).at(j);
    					rv.push_back(temp);
    					num++;
    					j--;
    				}
    				
    				while(i > row_lower_bound) {
    					temp = matrix.at(i).at(j);
    					rv.push_back(temp);
    					num++;
    					i--;
    				}
    				col_upper_bound--;
    				row_upper_bound--;
    				col_lower_bound++;
    				row_lower_bound++;
    				
    			}
    		}
    	}
    	return rv;
    }    
};
