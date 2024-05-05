//
// Created by yesonggao on 2024/5/5.
//
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> sums(n + 1);
        unordered_map<int, int> caches;
        int ans = 0;
        caches[0] = 1;
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i-1] + nums[i-1];
            ans += caches[sums[i] - k];
            caches[sums[i]]++;
        }


        return ans;
    }
};