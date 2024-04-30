//
// Created by yesonggao on 2024/4/30.
//
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        const int N = 1e3 + 10;
        const int M = 1e3 + 10;
        int f[N][M] = {0};
        int n = nums.size();
        vector<int> values(n, 1);
        memset(f, -0x3f, sizeof(f));

        f[0][0] = 0;

        for (int i = 0; i <= n; i++) {
            f[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                int val = nums[i-1];
                if (j < val) {
                    f[i][j] = f[i-1][j];
                } else {
                    f[i][j] = max(f[i-1][j], f[i-1][j-val] + 1);
                }

            }
        }
        return max(f[n][target], -1);
    }
};