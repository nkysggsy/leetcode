//
// Created by yesonggao on 2024/5/3.
//
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int N = 200 + 10;
        int dist[N][N] = {0};
        int m = grid.size();
        int n = grid[0].size();


        for (int i = 1; i <= m; i++) {
            dist[i][1] = dist[i - 1][1] + grid[i-1][0];
            // cout << dist[i][1] << " ";
        }
        // cout << endl;

        for (int j = 1; j <= n; j++) {
            dist[1][j] = dist[1][j-1] + grid[0][j-1];
        }
        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                dist[i][j] = min(dist[i][j-1], dist[i-1][j]) + grid[i-1][j-1];
            }
        }
        return dist[m][n];
    }
};