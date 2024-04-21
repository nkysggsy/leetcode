//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int l = 0, r = nums.size();
        int pos = 0;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= 1) r = m;
            else
                l = m + 1;
        }
        int n = nums.size();
        pos = max(0,n - l);
        l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= 0) r = m;
            else l = m + 1;
        }
        int neg = max(0, l);
        return max(pos, neg);
    }