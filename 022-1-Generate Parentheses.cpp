class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, n);
        return res;
    }
    
    void helper(vector<string> &Astr, string str, int i, int j) {
        if (i == 0 && j == 0) {
            Astr.push_back(str);
            return;
        }
        if (i > 0)
            helper(Astr, str+"(", i-1, j);
        if (j > i)
            helper(Astr, str+")", i, j-1);
    }
};
