//
// Created by yesonggao on 2024/5/3.
//
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        const int N = 1e5 + 10;
        typedef long long LL;
        // 0 , 1
        LL f[N][2] = {0};
        const LL MIN_VAL = -1e11;
        int val = nums[0] % 2;
        f[0][val] = nums[0];
        f[0][1- val] = MIN_VAL;

        for (int i = 1; i < n; i++) {
            if (nums[i] % 2) {
                f[i][0] = f[i-1][0];
                f[i][1] = max(f[i-1][1] + nums[i], f[i-1][0] + nums[i] - x);
            } else {
                f[i][0] = max(f[i-1][0] + nums[i], f[i-1][1] + nums[i] - x);
                f[i][1] = f[i-1][1];
            }
        }
        return max(f[n-1][0], f[n-1][1]);
    }
};