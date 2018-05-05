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
            unordered_map<string, int> wordmap2;
            int j, left = i, count = lenwords;
            for (j = i; j <= s.size() - lenword; j += lenword) {
                string stmp = s.substr(j, lenword);
                if (wordmap[stmp]) {
                    --count;
                    ++wordmap2[stmp];
                    if (wordmap2[stmp] > wordmap[stmp]) {
                        while (wordmap2[stmp] > wordmap[stmp]) {
                            string stmp1 = s.substr(left, lenword);
                            ++count;
                            --wordmap2[stmp1];
                            left += lenword;
                        }
                    }                         
                    if (count == 0) {
                        res.push_back(left);
                        ++count;
                        --wordmap2[s.substr(left, lenword)];
                        left += lenword;
                    } 
                    
                } else {
                    wordmap2.clear();
                    count = lenwords;
                    left = j+lenword;
                }
            }
        }
        return res;
    }
};
