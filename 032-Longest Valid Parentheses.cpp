class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0, curlen = 0;
        stack<pair<int, int>> stk; // first-index, second-0 for '(', 1 for ')'
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stk.push(make_pair(i, 0));
            else {
                if (stk.empty() || stk.top().second == 1)
                    stk.push(make_pair(i, 1));
                else {
                    stk.pop();
                    if (stk.empty())
                        curlen = i + 1;
                    else
                        curlen = i - stk.top().first;
                    maxlen = max(maxlen, curlen);
                }
            }
        }
        return maxlen;
    }
};
