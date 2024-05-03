//
// Created by yesonggao on 2024/5/3.
//
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        const int N = 1e3 + 10;
        int f[N][N] = {0};
        f[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (text1[i] == text2[j])
                    f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
                else if (text1[i] != text2[j])
                    f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]);

        return f[n][m];
    }
};