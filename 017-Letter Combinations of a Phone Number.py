class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        res = []
        if len(digits) == 0:
            return res
        
        if len(digits) == 1:
            if digits[0] == '2':
                res.extend(('a', 'b', 'c'))
            elif digits[0] == '3':
                res.extend(('d', 'e', 'f'))
            elif digits[0] == '4':
                res.extend(('g', 'h', 'i'))
            elif digits[0] == '5':
                res.extend(('j', 'k', 'l'))
            elif digits[0] == '6':
                res.extend(('m', 'n', 'o'))
            elif digits[0] == '7':
                res.extend(('p', 'q', 'r', 's'))
            elif digits[0] == '8':
                res.extend(('t', 'u', 'v'))
            elif digits[0] == '9':
                res.extend(('w', 'x', 'y', 'z'))
            return res
        else:
            tmp1 = self.letterCombinations(digits[0])
            tmp2 = self.letterCombinations(digits[1:])
            tmp = []
            for i in range(len(tmp1)):
                for j in range(len(tmp2)):
                    tmp.append(tmp1[i] + tmp2[j])
            res = tmp
            return res
