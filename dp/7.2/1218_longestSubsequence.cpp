//
// Created by yesonggao on 2024/5/5.
//
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {

        unordered_map<int, vector<int>> indexs;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            indexs[arr[i]].push_back(i);

        vector<int> f(n, 1), g(n, 1);

        for (int i = 0; i < n; i++) {
            int val1 = arr[i] + difference;
            if (indexs.contains(val1))
                for (int j : indexs[val1])
                    if (j > i)
                        f[j] = max(f[j], f[i] + 1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, f[i]);
        return ans;
    }
};