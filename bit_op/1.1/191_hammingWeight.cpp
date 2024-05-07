//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        for (int i = 0; i < 31; i++)
            if ((n >> i) & 1) cnt++;

        return cnt;
    }
};