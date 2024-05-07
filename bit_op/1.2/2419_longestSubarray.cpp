//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n), g(n);
        for (int i = 0; i < n; i++) {
            f[i] = nums[i];
            g[i] = i;
        }

        for (int i = 1; i < n; i++ )
            if (f[i] <= (f[i - 1] & nums[i])) {
                f[i] = f[i - 1] & nums[i];
                g[i] = g[i - 1];
            }

        int max_val = INT_MIN, pos = 0;
        for (int i = 0; i < n; i++) {
            if (max_val <= f[i]) {
                max_val = f[i];
                pos = i;
            }
        }
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] == f[pos]) {
                len = max(len, i - g[i] + 1);
            }
        }
        return len;
    }
};