//
// Created by yesonggao on 2024/5/5.
//
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> sum(n + 1);

        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + check(words[i - 1]);

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = sum[queries[i][1] + 1] - sum[queries[i][0]];
        }
        return ans;
    }

    bool check(string& str) {

        if (str[0] != 'a' && str[0] != 'e' && str[0] != 'i' && str[0] != 'o' &&
            str[0] != 'u')
            return false;
        int c = str.back();
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
            return false;
        return true;
    }
};