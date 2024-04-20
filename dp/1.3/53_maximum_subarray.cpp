//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);

        int max_val = -1e4;
        for (int i = 0; i < n; i++) {
            f[i + 1] = max(nums[i], f[i] + nums[i]);
            max_val = max(f[i + 1], max_val);
        }
        return max_val;
    }
};