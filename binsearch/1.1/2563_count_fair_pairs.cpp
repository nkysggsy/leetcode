//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        typedef long long LL;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        LL cnt = 0;
        for (int i = 0; i < n; i++) {
            LL l = i + 1, r = n;
            int val = upper - nums[i];
            while (l < r) {
                LL m = l + (r - l) / 2;
                if (nums[m] > val) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            if (l - 1 <  i + 1) continue;
            LL end = l - 1;
            l = i + 1, r = n;
            val = lower - nums[i];
            while (l < r) {
                LL m = l + (r - l) / 2;
                if (nums[m] >= val) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            if (l < i + 1) continue;
            cnt += end - l + 1;
        }
        return cnt;
    }
};