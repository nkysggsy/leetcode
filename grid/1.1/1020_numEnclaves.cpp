//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int m;
    int n;
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    ans += bfs(grid, i, j);
                }
        return ans;
    }

    int bfs(vector<vector<int>>& grid, int a, int b) {
        typedef pair<int, int> PII;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        queue<PII> q;
        q.push(make_pair(a, b));
        grid[a][b] = 0;
        bool flag = true;
        int cnt = 1;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first;
            int y = t.second;
            if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
                flag = false;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || !grid[nx][ny])
                    continue;
                grid[nx][ny] = 0;
                q.push(make_pair(nx, ny));
                cnt++;
            }
        }
        return flag ? cnt : 0;
    }
};