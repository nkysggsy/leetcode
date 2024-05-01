//
// Created by yesonggao on 2024/5/1.
//
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        const int N = 110;
        int f[N] = {0};
        for (int i = 0; i < n; i++) f[i] = 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[j] <= nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, f[i]);
        return n - ans;
    }
};