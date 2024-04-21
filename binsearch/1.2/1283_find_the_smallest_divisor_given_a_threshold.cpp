//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e7;

        while (l < r) {
            int mid = l + (r - l) / 2;
            int sum = 0;
            for (int num : nums) {
                sum += (num + mid - 1) / mid;
            }
            if (sum <= threshold) {
                r = mid;
            } else
                l = mid + 1;
        }
        return l;
    }
};