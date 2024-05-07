//
// Created by yesonggao on 2024/5/8.
//
class Solution {
    int m;
    int n;

public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int total = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    total++;

        int time = 0;
        typedef pair<int, int> PII;
        queue<PII> q, q1;
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                        grid[nx][ny] != 1) {
                        continue;
                    }
                    q1.push(make_pair(nx, ny));
                    cnt++;
                    grid[nx][ny] = 2;
                }
            }
            time++;
            q.swap(q1);
        }
        return cnt == total ? max(time - 1, 0) : -1;
    }
};