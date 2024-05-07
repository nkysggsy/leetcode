//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        int ans = 0;
        typedef pair<int, int> PII;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!grid[i][j]) {
                    queue<PII> q;
                    bool flag = true;
                    q.push(make_pair(i, j));
                    grid[i][j] = 1;
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        if (t.first == 0 || t.first == m - 1 || t.second == 0 || t.second == n - 1) {
                            flag = false;
                        }
                        for (int k = 0; k < 4; k++) {
                            int x = t.first + dx[k];
                            int y = t.second + dy[k];
                            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y])
                                continue;
                            q.push(make_pair(x,y));
                            grid[x][y] = 1;
                        }

                    }
                    if (flag) ans++;
                }
        return ans;
    }
};