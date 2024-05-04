//
// Created by yesonggao on 2024/5/4.
//
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        const int N = 5e2 + 10;
        int f[N][N] = {0};
        f[0][0] = 0;
        for (int i = 1; i <= n;i++) f[i][0] = i;
        for (int j = 1; j <= m;j++) f[0][j] = j;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m ; j++)
                if (word1[i] == word2[j]) {
                    f[i + 1][j + 1] = f[i][j];
                } else {
                    f[i+1][j+1] = f[i][j] + 1;
                    f[i+1][j+1] = min(f[i+1][j+1], min(f[i][j+1], f[i+1][j])+1);
                }
        return  f[n][m];
    }
};