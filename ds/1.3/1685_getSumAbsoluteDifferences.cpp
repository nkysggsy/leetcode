//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];

        for (int i = 0; i < n; i++) {
            ans[i] = i * nums[i] - sums[i] + sums[n] - sums[i + 1] -
                     (n - i - 1) * nums[i];
        }
        return ans;
    }
};