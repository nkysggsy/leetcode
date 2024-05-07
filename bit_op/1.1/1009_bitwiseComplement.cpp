//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int x = 1;
        while (n >= x) {
            x = x << 1;
        }
        return x - n - 1;
    }
};