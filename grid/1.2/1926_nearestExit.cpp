//
// Created by yesonggao on 2024/5/8.
//
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int x = entrance[0];
        int y = entrance[1];

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        typedef pair<int, int> PII;
        queue<PII> q;
        q.push(make_pair(x, y));
        vector<vector<int>> dist(m, vector<int>(n, -1));
        dist[x][y] = 0;

        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int a = t.first;
            int b = t.second;
            if ((a == 0 || a == m - 1 || b == 0 || b == n - 1) &&
                dist[a][b] > 0)
                return dist[a][b];
            for (int i = 0; i < 4; i++) {
                int na = a + dx[i];
                int nb = b + dy[i];
                if (na < 0 || na >= m || nb < 0 || nb >= n ||
                    maze[na][nb] == '+' || dist[na][nb] != -1)
                    continue;
                q.push(make_pair(na, nb));
                dist[na][nb] = dist[a][b] + 1;
            }
        }
        return -1;
    }
};