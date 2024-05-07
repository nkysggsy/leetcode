//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int nums1[30] = {0};
        int nums2[30] = {0};
        int total = 0;
        for (int i = 0; i < 30; i++) {
            if ((start >> i) & 1) nums1[i] = 1;
            if ((goal >> i) & 1) nums2[i] = 1;
            total += (nums1[i] != nums2[i]);
        }
        return total;
    }
};