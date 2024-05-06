//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> hashes;
        hashes[0] = -1;
        int start = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (hashes.contains(sum - target) &&
                start <= hashes[sum - target] + 1) {
                ans++;
                start = i + 1;
            }
            hashes[sum] = i;
        }
        return ans;
    }
};