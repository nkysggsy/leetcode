//
// Created by yesonggao on 2024/5/5.
//
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        unordered_map<int, int> caches;
        caches[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
            ans += caches[sums[i] - goal];
            caches[sums[i]]++;
        }
        return ans;
    }
};