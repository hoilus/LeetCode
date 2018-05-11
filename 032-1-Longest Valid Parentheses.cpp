class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.size(); i++) {
            int t = stk.top();
            if (t!=-1  && s[i] == ')' && s[t] == '(') {
                stk.pop();
                maxlen = max(maxlen, i - stk.top());
            }
            else
                stk.push(i);
        }
        return maxlen;
    }
};
