class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        check = False
        prefix = ''
        strs.sort(key=len)
        
        if len(strs) == 0 or len(strs[0]) == 0:
            return ''
        
        if len(strs) == 1:
            return strs[0]
        
        for i in range(len(strs[0])):
            for j in range(1,len(strs)):
                if (i < len(strs[j]) and strs[j][i] != strs[0][i]):
                    check = True
                    break
            if check == False and j == len(strs)-1:
                prefix += strs[0][i]
                check = False
            else:
                return prefix
        return prefix
