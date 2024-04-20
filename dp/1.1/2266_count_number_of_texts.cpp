//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int countTexts(string pressedKeys) {
        const int N = 1e5 + 10;
        const int MOD = 1e9 + 7;
        typedef long long LL;
        LL f[N] = {1, 1,2};
        LL g[N] = {1, 1, 2, 4};
        int n = pressedKeys.size();
        for (int i = 3; i <= n; i++) {
            f[i] = (f[i-1]  + f[i - 2] + f[i - 3]) % MOD;
        }

        for (int i = 4; i <= n; i++) {
            g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i-4]) % MOD;
        }
        pressedKeys += '0';
        LL sum = 1;
        int cnt = 1;
        for (int i = 1; i < pressedKeys.size(); i++) {
            if (pressedKeys[i - 1] != pressedKeys[i]) {
                if (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') {
                    sum = sum * g[cnt] % MOD;
                } else {
                    sum = sum * f[cnt] % MOD;
                }
                //  cout << cnt << endl;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        return sum;
    }
};