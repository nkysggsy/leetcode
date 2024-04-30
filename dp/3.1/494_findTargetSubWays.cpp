//
// Created by yesonggao on 2024/4/30.
//
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        int v = sum - target;
        if (v % 2 || v < 0) return 0;
        v = v / 2;
        int f[1010] = {0};
        f[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = v; j >= nums[i]; j--)
                f[j] += f[j - nums[i]];
        }
        return f[v];
    }
};