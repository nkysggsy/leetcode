//
// Created by yesonggao on 2024/5/5.
//
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> caches;
        int sum = 0;
        int ans = 0;
        caches[0] = 1;
        for (int num : nums) {
            sum += num;
            int val = (sum % k + k) % k;
            if (!caches.contains(val)) {
                caches[val] = 1;
            } else {
                ans += caches[val];
                caches[val]++;
            }
        }
        return ans;
    }
};