//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        typedef pair<int, int> PII;
        queue<PII> q;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!mat[i][j]) dist[i][j] = 0, q.push(make_pair(i, j));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = t.first + dx[i];
                int y = t.second + dy[i];
                if (x < 0 || x >= m || y < 0 || y >= n || dist[x][y] != -1) {
                    continue;
                }
                dist[x][y] = dist[t.first][t.second] + 1;
                q.push(make_pair(x,y));
            }
        }
        return dist;
    }
};