//
// Created by yesonggao on 2024/5/3.
//
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        const int N = 1e3 + 10;
        int f[n][2];
        // 0 delta < 0, 1 delta > 0
        for (int i = 0; i < n; i++) f[i][0] = f[i][1] = 1;

        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++) {
                if (nums[i] < nums[j]) {
                    f[i][0] = max(f[i][0], f[j][1] + 1);
                }
                if (nums[i] > nums[j]) {
                    f[i][1] = max(f[i][1],  f[j][0] + 1);
                }
            }
        return max(f[n-1][0], f[n-1][1]);
    }
};