class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int lenword = words[0].size(), lenwords = words.size();
        if (s.size() < lenword*lenwords) return res;
        unordered_map<string, int> wordmap;
        for (const auto &a : words) ++wordmap[a];
        for (int i = 0; i <= (s.size() - lenword*lenwords); i++) {
            unordered_map<string, int> wordmap2;
            int j;
            // why (int j = 0; j < lenwords; j++) always give outer j as 0???
            // do not double define the same variable in both outer and inner loops.
            // if so, inner loop can not see the outer one, and vise versa, becuase the two loops have different scopes.
            for (j = 0; j < lenwords; j++) {
                string stmp = s.substr(i+j*lenword, lenword);
//                cout << stmp << "  " << j << endl;
                if (wordmap.find(stmp) == wordmap.end()) break;
                ++wordmap2[stmp];
                if (wordmap2[stmp] > wordmap[stmp]) break;
            }
//            cout << "outer j = " << j << endl;
            if (j == lenwords) res.push_back(i);
        }
        return res;
    }
};  
