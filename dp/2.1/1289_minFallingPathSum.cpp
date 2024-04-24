//
// Created by yesonggao on 2024/4/24.
//
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> f(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
            f[0][i] = grid[0][i];

        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    if (k == j) continue;
                    f[i][j] = min(f[i][j], f[i - 1][k] + grid[i][j]);
                }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, f[n - 1][i]);
        return ans;
    }
};