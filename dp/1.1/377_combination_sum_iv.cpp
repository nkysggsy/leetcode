//
// Created by yesonggao on 2024/4/20.
//

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        const int M = 1000 + 10;
        unsigned f[M] = {0};
        for (int num : nums) {
            f[num] = 1;
        }
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    f[i] += f[i - num];
                }
            }
        }
        return f[target];
    }
};