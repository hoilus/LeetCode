class Solution {
public:
    bool anyDuplicate(vector<char> subMat) {
        string nums = "123456789";
        string::size_type pos = 0;
        for (auto ich : subMat) {
            if ((ich != '.') && ((pos = nums.find_first_of(ich)) != std::string::npos))
                nums.erase(pos, 1);
            else if ((ich != '.') && ((pos = nums.find_first_of(ich)) == std::string::npos))
                return false;
        }
//        cout << nums << endl;
        return true;
    } 
    
    bool isValidSudoku(vector<vector<char>>& board) {
        // naive solution
        // loop all rows and cols as well as all the 9 3x3 sub-matrices
        if ((board.size() != 9) || (board[0].size() != 9)) return false;
        for (int i = 0; i < 9; ++i) {
            // row
            if (anyDuplicate(board[i]) == false)
                return false;
            // column
            vector<char> tmp = {};
            for (int j = 0; j < 9; ++j) 
                tmp.push_back(board[j][i]);
            if (anyDuplicate(tmp) == false)
                return false;
            // sub-matrix
            vector<char> tmp1 = {};
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    tmp1.push_back(board[(i/3)*3 + j][(i%3)*3 + k]);
            if (anyDuplicate(tmp1) == false)
                return false;
        }
        return true;
    } 
};
