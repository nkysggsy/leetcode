//
// Created by yesonggao on 2024/5/2.
//
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int f[n][2];
        memset(f, 0, sizeof(f));
        if (nums[0] > 0) {
            f[0][1] = 1;
        }
        if (nums[0] < 0) {
            f[0][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                f[i][1] = f[i-1][1] + 1;
                if (f[i-1][0]) f[i][0] = f[i-1][0] + 1;
            } else if (nums[i] < 0){
                f[i][0] = f[i-1][1] + 1;
                if (f[i-1][0] )f[i][1] = f[i-1][0] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans ,f[i][1]);
        return ans;
    }
};