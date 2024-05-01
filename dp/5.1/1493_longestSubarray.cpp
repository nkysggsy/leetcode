//
// Created by yesonggao on 2024/5/1.
//
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n ; i++)
            sum[i + 1] = sum[i] + nums[i];

        int len = 0;
        // [i, j]
        for (int i = 1, j = 1; i <= j && j <= n; ) {
            while (j <= n && sum[j] - sum[i - 1] + 1 >= j - i + 1) j++;
            len = max(len, j - i-1);
            i++;
        }
        return len;
    }
};