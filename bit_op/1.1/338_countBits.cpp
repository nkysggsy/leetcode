//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for (int i = 1; i <= n; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};