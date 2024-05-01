//
// Created by yesonggao on 2024/5/1.
//
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        vector<int> g(n, 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) f[i] = max(f[i], f[j] + 1);
            }

        for (int i = n - 1; i  > 0; i--)
            for (int j = i - 1; j > 0; j--)
                if (nums[i] < nums[j]) g[j] = max(g[j], g[i] + 1);



        int ans = 0;
        for (int i = 0; i < n; i++)
            if (f[i] != 1 && g[i] != 1)
                ans = max(ans, f[i] + g[i] - 1);

        return n  - ans;

    }
};