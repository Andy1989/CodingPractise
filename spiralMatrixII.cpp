/* Spiral Matrix II 
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * 
 * For example,
 * Given n = 3,
 * 
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 */
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int> > rv;;
    	
    	if(n < 1) {
    		return rv;
    	}
    	
    	vector<vector<int> > matrix(n, vector<int>(n, 0));
    	unsigned int total = n * n;
    	unsigned int row_lower_bound = 0;
    	unsigned int row_upper_bound = n - 1;
    	unsigned int col_lower_bound = 0;
    	unsigned int col_upper_bound = n - 1;
    	for(unsigned int i = row_lower_bound, j = col_lower_bound, num = 1 ; num <= total; i = row_lower_bound, j = col_lower_bound) {
    		if(row_lower_bound == row_upper_bound) {
    			while(j <= col_upper_bound) {
    				matrix.at(i).at(j) = num;
    				num++;
    				j++;
    			}
    			continue;
    		}
    		
    		if(col_lower_bound == col_upper_bound) {
    			while(i <= row_upper_bound) {
    				matrix.at(i).at(j) = num;
    				num++;
    				i++;
    			}
    			continue;
    		}
    		while(j < col_upper_bound) {
    			matrix.at(i).at(j) = num;
    			num++;
    			j++;
    		}
    
    		while(i < row_upper_bound) {
    			matrix.at(i).at(j) = num;
    			num++;
    			i++;
    		}
    		
    		while(j > col_lower_bound) {
    			matrix.at(i).at(j) = num;
    			num++;
    			j--;
    		}
    		
    		while(i > row_lower_bound) {
    			matrix.at(i).at(j) = num;
    			num++;
    			i--;
    		}
    		col_upper_bound--;
    		row_upper_bound--;
    		col_lower_bound++;
    		row_lower_bound++;
    		
    	}
    	
    	return matrix;
    }

};
