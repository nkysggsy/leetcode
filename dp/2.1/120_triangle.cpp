//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        const int N = 200 + 10;
        int dist[N][N] = {0};

        memset(dist, 0x3f, sizeof(dist));
        dist[0][1] = 0;
        for (int i = 1; i <= n; i++) {
            dist[i][1] = dist[i-1][1] + triangle[i-1][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i; j++) {
                dist[i + 1][j] = min(dist[i+1][j], dist[i][j] + triangle[i][j]);
                dist[i+1][j+1] = min(dist[i+1][j+1], dist[i][j] + triangle[i][j]);
            }
        }
        int ans = 1e7;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, dist[n][i]);
        }
        return ans;
    }
};