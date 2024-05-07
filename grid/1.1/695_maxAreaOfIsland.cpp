//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        typedef pair<int, int> PII;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    int cnt = 0;
                    queue<PII> q;
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        cnt++;
                        for (int i = 0; i < 4; i++) {
                            int x = t.first + dx[i];
                            int y = t.second + dy[i];
                            if (x < 0 || x >= m || y < 0 || y >= n ||
                                !grid[x][y])
                                continue;
                            q.push(make_pair(x, y));
                            grid[x][y] = 0;
                        }
                    }
                    ans = max(ans, cnt);
                }
        return ans;
    }
};