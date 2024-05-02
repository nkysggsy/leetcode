//
// Created by yesonggao on 2024/5/2.
//
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        vector<int> g(n, 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j]) {
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        g[i] = g[j];
                    } else if (f[i] == f[j] + 1) {
                        g[i] += g[j];
                    }
                }

        int max_val = 0;
        for (int i = 0; i < n; i++)
            max_val = max(max_val, f[i]);

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (f[i] == max_val) ans += g[i];

        return ans;
    }
};