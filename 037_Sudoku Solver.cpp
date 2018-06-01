class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int notfilling = 1, needToUpd;

        while (notfilling != 0) {
            notfilling = 0;
            needToUpd = 0;
            // updating 27 vectors (9 rows, 9 cols and 9 sub-matrices)
            vector<string> updatedVec = updAllVec(board);
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        notfilling += 1;
                        string sol1 = possSol(updatedVec[i], updatedVec[9+j], updatedVec[18+(i/3)*3+(j/3)]);
                        if ((sol1.size()) == 1) {
                            needToUpd += 1;
                            board[i][j] = sol1[0];
                        }
                        else {
                            string str1, str2, str3, str4;
                            if (i%3 == 0) {
                                str1 = updatedVec[i+1];
                                str2 = updatedVec[i+2];
                            } else if (i%3 == 1) {
                                str1 = updatedVec[i-1];
                                str2 = updatedVec[i+1];            
                            } else {
                                str1 = updatedVec[i-1];
                                str2 = updatedVec[i-2];
                            }

                            if (j%3 == 0) {
                                str3 = updatedVec[9+j+1];
                                str4 = updatedVec[9+j+2];
                            } else if (j%3 == 1) {
                                str3 = updatedVec[9+j-1];
                                str4 = updatedVec[9+j+2];          
                            } else {
                                str3 = updatedVec[9+j-1];
                                str4 = updatedVec[9+j-2];
                            }
                            string sol2 = possSol2(sol1, str1, str2, str3, str4);
                            if ((sol2.size()) == 1) {
                                needToUpd += 1;
                                board[i][j] = sol2[0];
                            }
                        }
                    }
                }
            }
        }

    }
    
    vector<string> updAllVec(vector<vector<char>> board) {
        vector<string> updated;
        string allNums = "123456789";
        string::size_type pos = 0;
        for (int i = 0; i < 9; i++) {
            updated.push_back("");
            for (auto chr : board[i]) {
                if ((pos = allNums.find_first_of(chr)) != std::string::npos)
                    updated[i].append(string(1,chr));
            }
        }
        for (int i = 0; i < 9; i++) {
            updated.push_back("");
            for (int j = 0; j < 9; j++) {
                if ((pos = allNums.find_first_of(board[j][i])) != std::string::npos)
                    updated[9+i].append(string(1,board[j][i]));
            }
        }
        for (int i = 0; i < 9; i++) {
            updated.push_back("");
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if ((pos = allNums.find_first_of(board[(i/3)*3+j][(i%3)*3+k])) != std::string::npos)
                        updated[9*2+i].append(string(1,board[(i/3)*3+j][(i%3)*3+k]));
                }
            }
        }
        return updated;
    }
    
    string possSol(string st1, string st2, string st3) {
        vector<string> strs = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
        string reslt;
        for (auto i : strs)
            if ((st1.find(i) == std::string::npos) && (st2.find(i) == std::string::npos) && (st3.find(i) == std::string::npos))
                reslt.append(i);
        return reslt;
    }

    string possSol2(string strtmp, string str1, string str2, string str3, string str4) {       
        string reslt;
        for (int i = 0; i < strtmp.size(); i++)
            if ((str1.find(strtmp[i]+"") != std::string::npos) && (str2.find(strtmp[i]+"") != std::string::npos) && (str3.find(strtmp[i]+"") != std::string::npos) && (str4.find(strtmp[i]+"") != std::string::npos))
                reslt.append(strtmp[i]+"");
        return reslt;
    }
};
