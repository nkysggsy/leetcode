//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        typedef long long LL;
        vector<int> f(high + 1, 0);
        const int MOD = 1e9 + 7;
        f[0] = 1;
        int x = min(zero, one);
        int y = max(zero, one);
        int sum = 0;
        for (int i = 1; i <= high; i++) {
            if (i >= x)
                f[i] = (f[i] + f[i - x]) % MOD;
            if (i >= y)
                f[i] = (f[i] + f[i - y]) % MOD;
            if (i >= low)
                sum = (sum + f[i]) % MOD;
        }

        return sum;
    }
};