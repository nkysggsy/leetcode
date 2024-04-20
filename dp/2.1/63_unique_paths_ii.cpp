//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        const int N = 110;
        int dist[N][N] = {0};

        dist[0][0] = !obstacleGrid[0][0] ? 1 : 0;
        for (int i = 1; i < n; i++) {
            if (!obstacleGrid[0][i]) {
                dist[0][i] += dist[0][i-1];
            }
        }

        for (int j = 1; j < m; j++) {
            if (!obstacleGrid[j][0]) {
                dist[j][0] += dist[j-1][0];
            }
        }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) {
                if (!obstacleGrid[i][j]) {
                    dist[i][j] += dist[i-1][j];
                    dist[i][j] += dist[i][j-1];
                }
            }
        return dist[m-1][n-1];
    }
};