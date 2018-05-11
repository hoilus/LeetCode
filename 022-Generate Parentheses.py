class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        self.helper(res, "", n, n)
        return res
    
    def helper(self, res, strs, left, right):
        if (left == 0 and right == 0):
            res.append(strs)
            return
        if (left > 0):
            self.helper(res, strs+'(', left-1, right)
        if (right > left):
            self.helper(res, strs+')', left, right-1)
        
