//
// Created by yesonggao on 2024/4/24.
//
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        typedef long long LL;
        LL f[m][n][2];
        f[0][0][0] = f[0][0][1] = grid[0][0];

        for (int i = 1; i < m; i++) {
            f[i][0][0] = f[i][0][1] = f[i-1][0][0] * grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            f[0][j][0] = f[0][j][1] = f[0][j-1][0] * grid[0][j];
        }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    f[i][j][1] = max(f[i][j-1][1], f[i-1][j][1])  * grid[i][j];
                    f[i][j][0] = min(f[i][j-1][0], f[i-1][j][0])  * grid[i][j];
                } else {
                    f[i][j][1] = min(f[i][j-1][0], f[i-1][j][0]) * grid[i][j];
                    f[i][j][0] = max(f[i][j-1][1], f[i-1][j][1]) * grid[i][j];
                }
                //   cout <<  " i " << i << " j " << j << " " << f[i][j][0] << " " << f[i][j][1] << endl;
            }
        return f[m-1][n-1][1] < 0 ? -1 : f[m-1][n-1][1] % MOD;
    }
};