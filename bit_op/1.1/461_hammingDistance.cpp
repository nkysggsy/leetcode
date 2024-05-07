//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int hammingDistance(int x, int y) {
        int val = x ^ y;
        int total = 0;
        while (val) {
            total += val & 1;
            val = val >> 1;
        }
        return total;
    }
};