//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        const int MAX = 1e6 + 1;
        int l = 0, r = MAX;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (check(heights, rows, cols, m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }

    bool check(vector<vector<int>>& heights, int rows, int cols, int diff) {
        typedef pair<int, int> PII;
        queue<PII> q;
        q.push(make_pair(0,0));
        vector<bool> visit(rows * cols, false);
        visit[0] = true;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.first == rows - 1 && t.second == cols - 1) return true;
            for (int i = 0; i < 4; i++) {
                int x = t.first + dx[i];
                int y = t.second + dy[i];
                if (x < 0 || x >= rows || y < 0 || y >= cols || visit[x * cols+y] || abs(heights[x][y] - heights[t.first][t.second]) > diff)
                    continue;
                else
                {
                    visit[x * cols+y] = true;
                    q.push(make_pair(x, y));
                }
            }
        }
        return false;
    }
};