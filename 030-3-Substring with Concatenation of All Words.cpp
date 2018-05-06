class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int lenword = words[0].size(), lenwords = words.size(), count = lenwords;
        if (s.size() < lenword*lenwords) return res;
        unordered_map<string, int> wordmap;
        for (const auto &a : words) ++wordmap[a];
        for (int i = 0; i < lenword; i++) {
            unordered_map<string, int> wordmap2 = wordmap;
            int j, count = lenwords;
            for (j = i; j <= s.size() - lenword; j += lenword) {
                string stmp = s.substr(j, lenword);
                if (wordmap2[stmp]-- > 0) --count;
                if (j - lenword*lenwords >= 0) {
                    string stmpt = s.substr(j-lenword*lenwords, lenword);
                    if (++wordmap2[stmpt] > 0) ++count;
                }
                if (count == 0) res.push_back(j - (lenwords-1)*lenword);
            }
        }
        return res;
    }
};
