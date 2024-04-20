//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N =1e4 + 10;
        int vals[N] = {0};
        int r = 0;
        for (int num : nums) {
            vals[num] += num;
            r = max(r, num);
        }
        int f[N][2] = {0};
        for (int i = 1; i <= r; i++) {
            f[i + 1][1] = f[i][0] + vals[i];
            f[i + 1][0] = max(f[i][0], f[i][1]);
        }
        return max(f[r+1][0], f[r+1][1]);
    }
};