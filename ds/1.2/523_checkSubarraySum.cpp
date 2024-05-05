//
// Created by yesonggao on 2024/5/5.
//
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> caches;
        caches[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int val = sum % k;
            if (!caches.contains(val)) {
                caches[val] = i;
            } else {
                int prev = caches[val];
                if (i - prev >= 2)
                    return true;
            }
        }
        return false;
    }
};