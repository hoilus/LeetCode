class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
        solSudoku(board, 0, 0);
    }
    
    bool solSudoku(vector<vector<char>>& board, int irow, int jcol) {
        if (irow == 9) return true;
        if (jcol >= 9) return solSudoku(board, irow+1, 0);
        if (board[irow][jcol] == '.') {
            for (int k = 1; k <= 9; ++k) {
                board[irow][jcol] = k + '0';
                if (valid(board, irow, jcol))
                    if(solSudoku(board, irow, jcol + 1)) return true;
                board[irow][jcol] = '.';
            }
        } else {
            return solSudoku(board, irow, jcol + 1);
        }
        return false;
    }
    
    bool valid(vector<vector<char>>& board, int i , int j) {
        for (int row = 0; row < 9; ++row) {
            if (row != i && board[i][j] == board[row][j]) return false;
        }
        for (int col = 0; col < 9; ++col) {
            if (col != j && board[i][j] == board[i][col]) return false;
        }
        for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row)
            for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col)
                if ((row != i && col != j) && (board[i][j] == board[row][col])) return false;
        return true;
    }
};
