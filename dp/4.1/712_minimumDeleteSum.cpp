//
// Created by yesonggao on 2024/5/4.
//
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        const int N = 1e3 + 10;
        int f[n + 1][m + 1];
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
            f[i][0] = f[i-1][0] + s1[i-1];

        for (int j = 1; j <= m; j++)
            f[0][j] = f[0][j-1] + s2[j-1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s1[i] == s2[j]) {
                    f[i+1][j+1] =  f[i][j];
                }
                else {
                    f[i+1][j+1] = min(f[i+1][j] + s2[j], f[i][j+1] + s1[i]);
                }
        return f[n][m];
    }
};