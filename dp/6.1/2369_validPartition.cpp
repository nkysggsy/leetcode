//
// Created by yesonggao on 2024/4/22.
//
class Solution {
public:
    bool check1(vector<int>& nums, int i) {
        return nums[i] == nums[i + 1];
    }

    bool check2(vector<int>& nums, int i) {
        if (nums[i] == nums[i+1] && nums[i] == nums[i+2]) return true;
        return nums[i] + 1 == nums[i + 1] && nums[i] + 2 == nums[i + 2];
    }

    bool validPartition(vector<int>& nums) {
        const int N = 1e5 + 10;
        bool f[N] = {false};
        f[0] = 1;
        int n = nums.size();
        for (int i = 2; i <= n; i++) {
            if (!f[i] && i >= 2) f[i] = f[i - 2] && check1(nums, i-2);
            if (!f[i] && i >= 3) f[i] = f[i - 3] && check2(nums, i-3);
        }
        return f[n];
    }
};