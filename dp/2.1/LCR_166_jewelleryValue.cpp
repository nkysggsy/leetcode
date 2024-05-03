//
// Created by yesonggao on 2024/5/3.
//
class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int m = frame.size();
        int n = frame[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        dist[0][0] = frame[0][0];


        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i == 0 && j > 0) dist[i][j] = dist[i][j - 1] + frame[i][j];
                else if (j == 0 && i > 0) dist[i][j] = dist[i-1][j] + frame[i][j];
                else if (i > 0 && j > 0) dist[i][j] = max(dist[i-1][j], dist[i][j-1]) + frame[i][j];
        return dist[m-1][n-1];
    }
};