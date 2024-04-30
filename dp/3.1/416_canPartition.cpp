//
// Created by yesonggao on 2024/4/30.
//
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int val : nums) {
            sum += val;
        }
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        //  cout << target << endl;
        int n = nums.size();
        int f[n + 10][target + 10];
        memset(f, 0, sizeof(f));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i-1]) f[i][j] = max(f[i-1][j], f[i-1][j-nums[i-1]] + nums[i-1]);
                else f[i][j] = f[i-1][j];
            }
        }
        // cout << f[n-1][target] << endl;
        return f[n-1][target] == target;

    }
};