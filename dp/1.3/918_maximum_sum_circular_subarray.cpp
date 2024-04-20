//
// Created by yesonggao on 2024/4/20.
//

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(nums);
        int ans_max = f[0];
        for (int i = 1; i < nums.size(); ++i) {
            f[i] = max(nums[i], f[i - 1] + nums[i] );
            ans_max = max(ans_max, f[i]);
        }
        vector<int> g(nums);
        int ans_min = g[0];
        int sum = g[0];
        for (int i = 1; i < nums.size(); ++i) {
            g[i] = min(nums[i], g[i-1] + nums[i]);
            ans_min = min(ans_min, g[i]);
            sum += nums[i];
        }
        if (ans_max < 0) {
            return ans_max;
        }
        return max(ans_max, sum - ans_min);
    }
};