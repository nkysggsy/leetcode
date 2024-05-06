//
// Created by yesonggao on 2024/5/6.
//
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        typedef long long LL;
        vector<LL> sums(n + 1, 0);

        unordered_map<int, int> hashs;
        LL ans = -1e14;
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
            if (!hashs.contains(nums[i - 1])) {
                hashs[nums[i - 1]] = i;
            } else {
                int prev = hashs[nums[i - 1]];
                if (sums[i - 1] < sums[prev - 1])
                    hashs[nums[i - 1]] = i;
            }

            if (hashs.contains(nums[i - 1] - k)) {
                int j = hashs[nums[i - 1] - k];
                ans = max(ans, sums[i] - sums[j - 1]);
            }
            if (hashs.contains(nums[i - 1] + k)) {
                int j = hashs[nums[i - 1] + k];
                ans = max(ans, sums[i] - sums[j - 1]);
            }
        }
        return ans == -1e14 ? 0 : ans;
    }
};