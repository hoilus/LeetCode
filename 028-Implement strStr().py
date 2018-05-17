class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        m = len(haystack)
        n = len(needle)
        if n == 0:
            return 0
        elif m == 0 and n != 0:
            return -1
        elif m == n:
            if haystack == needle:
                return 0
            else:
                return -1
        if n > m:
            return -1
        result = -1
        for i in range(m-n+1):
            if haystack[i:i+n] == needle[:]:
                result = i
                break
        return result
