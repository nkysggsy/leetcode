//
// Created by yesonggao on 2024/5/2.
//
class Solution {
public:
    int idx(int x) {
        return x  % 3;
    }
    int maxSumDivThree(vector<int>& nums) {
        const int N = 4e4 + 10;
        int n = nums.size();
        int f[n + 1][3];
        f[0][0] = 0, f[0][1] = INT_MIN, f[0][2] = INT_MIN;
        for (int i = 0; i < n; i++) {
            int r = nums[i] % 3;
            for (int j = 0; j < 3; j++) {
                f[i+1][j] = max(f[i][j], f[i][(3 + j -r) % 3] + nums[i]);
            }
        }
        return f[n][0];
    }
};