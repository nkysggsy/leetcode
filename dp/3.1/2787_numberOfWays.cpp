//
// Created by yesonggao on 2024/4/30.
//
class Solution {
public:
    int pow(int x, int n) {
        int val = 1;
        while (n) {
            if (n & 1) val *= x;
            x = x * x;
            n = n / 2;
        }
        return val;
    }
    int numberOfWays(int n, int x) {
        const int N = 310;
        int c[N] = {1};
        const int MOD = 1e9 + 7;
        int len = 1;
        for (int i = 2; i < N; i++) {
            int val = pow(i, x);
            if (val > n) {
                break;
            }
            c[len++] = val;
        }

        typedef long long LL;
        LL f[n+1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 0; i < len; i++) {
            for (int j = n; j >= c[i];j--) {
                f[j] += f[j -c[i]];
            }
        }
        return f[n] % MOD;
    }
};