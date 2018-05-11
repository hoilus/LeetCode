class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        maxlen = 0
        stack = [0]
        if n <= 1:
            return 0
        for i in range(n):
            if s[i] == '(':
                stack.append(0)
            else:   # s[i] == ')'
                if (len(stack) <= 1):
                    stack = [0]
                else:
                    val = stack.pop()
                    stack[-1] += val + 2
                    maxlen = max(maxlen, stack[-1])
        return maxlen
