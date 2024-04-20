//
// Created by yesonggao on 2024/4/20.
//

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int maps[26] = {0};
        for (int i = 0; i < 26; i++) {
            maps[i] = i + 1;
        }
        for (int i = 0; i < chars.size(); i++) {
            maps[chars[i] - 'a'] = vals[i];
        }
        int ans = 0, f = 0;
        for (char c : s) {
            f = max(f, 0) + maps[c - 'a'];
            ans = max(ans, f);
        }
        return ans;
    }
};