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
        lenwords = len(words); len1word = len(words[0]); totletters = len1word*lenwords; cnt = lenwords
        wordcounts = {}
        for i in range(lenwords):
            if words[i] in wordcounts:
                wordcounts[words[i]] += 1
            else:
                wordcounts[words[i]] = 1
        
        for i in range(len1word):
            cnt = lenwords
            wordcnt = wordcounts.copy()
            for j in range(i, len(s)-len1word+1, len1word):
                tmps = s[j:(j+len1word)]
                if (tmps in wordcnt):
                    wordcnt[tmps] -= 1
                    if wordcnt[tmps] >= 0:
                        cnt -= 1
                else:
                    wordcnt[tmps] = -1
                if (j - totletters >= 0):
                    tmpsout = s[(j-totletters):(j-totletters+len1word)]
                    wordcnt[tmpsout] += 1
                    if (wordcnt[tmpsout] > 0):
                        cnt += 1
                if cnt == 0:
                    res.append(j-(lenwords-1)*len1word)
        
        return res
