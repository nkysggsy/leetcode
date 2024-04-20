//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int robRange(vector<int>&nums, int l, int r) {
        const int N  = 100 + 10;
        int f[N][2] = {0};
        for (int i = l; i <= r; i++) {
            f[i + 1][1] = f[i][0] + nums[i];
            f[i + 1][0] = max(f[i][1], f[i][0]);
        }
        return max(f[r+1][0], f[r+1][1]);
    }

    int rob(vector<int>& nums) {
        const int N = 100 + 10;
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return  max(nums[0], nums[1]);
        }
        int f = nums[0] + robRange(nums, 2, n - 2);
        int g = robRange(nums, 1, n - 1);
        return max(f, g);
    }


};