class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // three matrices for the three rules
        int check_row[9][9] = {0}, check_col[9][9] = {0}, check_sub_box[9][9] = {0};
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' -1, k = i / 3 *3 + j / 3;
                    if (check_row[i][num] || check_col[j][num] || check_sub_box[k][num])
                        return false;
                    check_row[i][num] = check_col[j][num] = check_sub_box[k][num] = 1;
                }
        return true;
    }
};
