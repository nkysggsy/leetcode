//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }
        if (l == nums.size() || nums[l] != target) return -1;
        return l;
    }
};