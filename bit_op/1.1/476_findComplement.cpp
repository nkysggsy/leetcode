//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int findComplement(int num) {
        typedef long long LL;
        LL x = 1;
        while (num >= x) {
            x = x << 1;
        }
        return x - num - 1;
    }
};