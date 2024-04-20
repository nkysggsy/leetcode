//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        const int N = 1e5 + 10;
        int sum[N] = {0};
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, abs(nums[i]));
        }
        int min_pre_sum = 0, max_pre_sum = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, sum[i] - min_pre_sum);
            ans = max(ans, max_pre_sum - sum[i]);
            min_pre_sum = min(min_pre_sum, sum[i-1]);
            max_pre_sum = max(max_pre_sum, sum[i-1]);
        }
        return ans;
    }
};