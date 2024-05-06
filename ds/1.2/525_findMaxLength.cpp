//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1);
        unordered_map<int, int> hashs;
        int ans = 0;
        hashs[0] = -1;
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + (nums[i] == 0 ? -1 : 1);
            if (hashs.contains(sums[i + 1])) {
                ans = max(ans, i - hashs[sums[i + 1]]);
            } else {
                hashs[sums[i + 1]] = i;
            }
        }
        return ans;
    }
};