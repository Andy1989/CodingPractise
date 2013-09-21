/* Surrounded Regions
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region .
 *
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 */
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unsigned int row = board.size();
        if(row <= 2) {
            return;
        }
        unsigned int col = board.at(0).size();
        
        if(col <= 2) {
            return;
        }
        unsigned int i, j;
        
        vector<vector<int> > temp(row, vector<int>(col, 0));
    
        for(j = 0; j < col; j++) {
            DFS(0, j, board, temp, board.at(0).at(j));
        }
        
        for(i = 0; i < row; i++) {
            DFS(i, col - 1, board, temp, board.at(i).at(col - 1));
        }
        
        for(j = 0; j < col; j++) {
            DFS(row - 1, j, board, temp, board.at(row - 1).at(j));
        }
        
        for(i = 0; i < row; i++) {
            DFS(i, 0, board, temp, board.at(i).at(0));
        }
        
        for(i = 0; i < row; i++) {
            for(j = 0; j < col; j++) {
                if(temp.at(i).at(j) == 0) {
                    board.at(i).at(j) = 'X';
                }
            }
        }
    }
    
    void DFS(int row, int col, vector<vector<char>> &board, vector<vector<int>> &temp, char ch) {
        stack<int> bufferx;
        stack<int> buffery;
        bufferx.push(row);
        buffery.push(col);
        int x, y, flag = 1;
        if(ch == 'o' || ch == 'O') {
            flag = 2;
        }
        while(!bufferx.empty()) {
            x = bufferx.top();
            y = buffery.top();
            temp.at(x).at(y) = flag; // 2 <=> 'o'
            if(x - 1 >= 0) {
                if(board.at(x - 1).at(y) == ch && temp.at(x - 1).at(y) == 0) {
                    bufferx.push(x - 1);
                    buffery.push(y);
                    continue;
                }
            }
            if(x + 1 < board.size()) {
                if(board.at(x + 1).at(y) == ch && temp.at(x + 1).at(y) == 0) {
                    bufferx.push(x + 1);
                    buffery.push(y);
                    continue;
                }
            }
            if(y - 1 >= 0) {
                if(board.at(x).at(y - 1) == ch && temp.at(x).at(y - 1) == 0) {
                    bufferx.push(x);
                    buffery.push(y - 1);
                    continue;
                }
            }
            if(y + 1 < board.at(0).size()) {
                if(board.at(x).at(y + 1) == ch && temp.at(x).at(y + 1) == 0) {
                    bufferx.push(x);
                    buffery.push(y + 1);
                    continue;
                }
            }
            
            bufferx.pop();
            buffery.pop();
        }
    }    
};















 
