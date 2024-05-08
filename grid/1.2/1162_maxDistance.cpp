//
// Created by yesonggao on 2024/5/8.
//
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        typedef pair<int, int> PII;
        queue<PII> q, q1;
        vector<vector<bool>> visit(n, vector<bool>(n));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    q.push(make_pair(i, j));
                    visit[i][j] = true;
                }

        int ans = 0;

        int d = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto t = q.front();
                q.pop();
                int a = t.first;
                int b = t.second;
                for (int j = 0; j < 4; j++) {
                    int na = a + dx[j];
                    int nb = b + dy[j];
                    if (na < 0 || na >= n || nb < 0 || nb >= n ||
                        visit[na][nb]) {
                        continue;
                    }
                    visit[na][nb] = 1;
                    q1.push(make_pair(na, nb));
                }
            }
            ans = max(ans, d);
            d = d + 1;
            q = move(q1);
        }
        return ans == 0 ? -1 : ans;
    }
};