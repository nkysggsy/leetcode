//
// Created by yesonggao on 2024/4/24.
//
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int MAX_VAL = 2 * 1e6;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> f(m + 10, vector<int>(n + 10, MAX_VAL));
        for (int i = 0; i < n; i++)
            f[0][i] = grid[0][i];


        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    int a = grid[i-1][k];
                    // cout << a << " " << j << " " << moveCost[a][j] << endl;
                    f[i][j] = min(f[i][j], f[i-1][k] + grid[i][j] + moveCost[a][j]);
                }
        int ans = MAX_VAL;
        for (int i = 0; i < n; i++)
            ans = min(ans, f[m-1][i]);
        return ans;
    }
};