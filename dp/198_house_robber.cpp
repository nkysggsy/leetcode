//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = 100 + 10;
        int n = nums.size();
        int f[N][2] = {0}; // 1 stolen
        for (int i = 0; i < nums.size(); i++) {
            f[i+1][1] = f[i][0] + nums[i];
            f[i+1][0] = max(f[i][1],f[i][0]);
        }
        return max(f[n][0], f[n][1]);
    }
};