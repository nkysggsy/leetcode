//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int binaryGap(int n) {
        int cnt = 0;
        vector<int> bits;
        while (n) {
            if (n & 1) bits.push_back(cnt);
            n = n >> 1;
            cnt++;
        }
        int len = 0;
        for (int i = 1; i < bits.size(); i++)
            len = max(len, bits[i] - bits[i-1]);
        return len;
    }
};