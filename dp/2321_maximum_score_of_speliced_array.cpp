//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum1 = 0, sum2 = 0;
        int f_max = 0, max_val = 0, f_min = 0, min_val = 0;
        for (int i = 0; i < n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            f_max = max(f_max, 0) + nums2[i] - nums1[i];
            max_val = max(f_max, max_val);
            f_min = min(f_min, 0) + nums2[i] - nums1[i];
            min_val = min(f_min, min_val);
        }
        return max(sum1 + max_val,  sum2 - min_val);
    }
};