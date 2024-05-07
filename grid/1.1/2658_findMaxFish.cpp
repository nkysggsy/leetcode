//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        typedef pair<int, int> PII;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    int score = 0;
                    queue<PII> q;
                    q.push(make_pair(i, j));
                    score += grid[i][j];
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int x = t.first + dx[k];
                            int y = t.second + dy[k];
                            if (x < 0 || x >= m || y < 0 || y >= n ||
                                !grid[x][y])
                                continue;
                            q.push(make_pair(x, y));
                            score += grid[x][y];
                            grid[x][y] = 0;
                        }
                    }
                    ans = max(ans, score);
                }
        return ans;
    }
};