//
// Created by yesonggao on 2024/5/5.
//
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        typedef long long LL;
        unordered_map<LL, int> indexs;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            indexs[nums[i]] = i;
        }

        vector<int> f(n, 1);
        for (int i = 0; i < n; i++)
            if (indexs.contains(1LL * nums[i] * nums[i])) {
                int j = indexs[1LL * nums[i] * nums[i]];
                f[j] = max(f[j], f[i] + 1);
            }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, f[i]);
        return ans >= 2 ? ans : -1;
    }
};