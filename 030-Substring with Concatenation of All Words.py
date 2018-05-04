class Solution:
    def findSubstring(self, s, words):
        """
        
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        res = []
        if (len(words) == 0) or (len(s) == 0):
            return res
        lenwords = len(words)
        len1word = len(words[0])
        totletters = len1word*lenwords
        for i in range(len(s)-totletters+1):
            tmpwords = words[:]
            for j in range(lenwords):
                tmps = s[(i+j*len1word):(i+(j+1)*len1word)]
                if tmps in tmpwords:
                    tmpwords.remove(tmps)
                else:
                    break
            if len(tmpwords) == 0:
                res.append(i)
        return res
