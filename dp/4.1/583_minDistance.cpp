class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        const int N = 5e2 + 10;
        int f[N][N] = {0};
        f[0][0] = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m ; j++)
                if (word1[i] == word2[j]) {
                    f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
                } else {
                    f[i+1][j+1] = max(f[i][j+1], f[i+1][j]);
                }
        return  n + m - 2 * f[n][m];
    }
};