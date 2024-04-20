//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int N = 100 + 10;
        int dist[N][N] = {0};
        memset(dist, 0x3f, sizeof(dist));
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            dist[0][i] = matrix[0][i];
        }


        for (int i = 0; i + 1< n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dist[i + 1][j] = min(dist[i+1][j], dist[i][j] + matrix[i+1][j]);
                    dist[i + 1][j + 1] = min(dist[i+1][j+1], dist[i][j] + matrix[i+1][j+1]);
                } else if (j == n - 1) {
                    dist[i+1][j - 1] = min(dist[i+1][j-1], dist[i][j] + matrix[i+1][j-1]);
                    dist[i + 1][j] = min(dist[i+1][j], dist[i][j] + matrix[i+1][j]);
                } else {
                    dist[i+1][j - 1] = min(dist[i+1][j-1], dist[i][j] + matrix[i+1][j-1]);
                    dist[i + 1][j] = min(dist[i+1][j], dist[i][j] + matrix[i+1][j]);
                    dist[i + 1][j + 1] = min(dist[i+1][j+1], dist[i][j] + matrix[i+1][j+1]);
                }
            }
        }
        int ans = 1e4;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dist[n-1][i]);
        }
        return ans;
    }
};