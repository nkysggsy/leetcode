//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        for (int i = 0; i < 11; i++)
            if ((n >> i) & 1) {
                if (i % 2 == 0) even++;
                else odd++;
            }

        return {even, odd};
    }
};