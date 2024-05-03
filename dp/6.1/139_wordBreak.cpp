//
// Created by yesonggao on 2024/5/3.
//
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> f(n+1);
        if (s.empty()) return false;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        f[0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                if (f[j]  && wordSet.contains(s.substr(j, i - j))) {
                    f[i] = true;
                    break;
                }

        return f[n];
    }
};