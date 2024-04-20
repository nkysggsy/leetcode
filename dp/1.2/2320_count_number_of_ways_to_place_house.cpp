//
// Created by yesonggao on 2024/4/20.
//

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countHousePlacements(int n) {
        typedef long long LL;
        vector<LL> f(n + 1);
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i <= n; i++)
            f[i] = (f[i - 1] + f[i - 2]) % MOD;
        return (f[n] * f[n]) % MOD;
    }
};