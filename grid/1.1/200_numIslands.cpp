//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    cnt++;
                    walk(grid, i, j);
                }
        return cnt;
    }

    void walk(vector<vector<char>>& grid, int i, int j) {
        typedef pair<int, int> PII;
        queue<PII> q;
        grid[i][j] = '0';
        q.push(make_pair(i, j));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = { 0, 0, -1, 1};

        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty()) {
            auto val = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = val.first + dx[i];
                int y = val.second + dy[i];
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0')
                    continue;
                else {
                    grid[x][y] = '0';
                    q.push(make_pair(x, y));
                }
            }
        }
    }
};