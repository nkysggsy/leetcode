//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        typedef pair<int, int> PII;
        vector<vector<bool>> visit(m, vector<bool>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O' && !visit[i][j]) {
                    queue<PII> q;
                    vector<PII> res;
                    q.push(make_pair(i, j));
                    res.push_back(make_pair(i, j));
                    visit[i][j] = true;
                    bool flag = true;
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        if (t.first == 0 || t.first == m - 1 || t.second == 0 ||
                            t.second == n - 1)
                            flag = false;
                        for (int k = 0; k < 4; k++) {
                            int x = t.first + dx[k];
                            int y = t.second + dy[k];
                            if (x < 0 || x >= m || y < 0 || y >= n ||
                                visit[x][y] || board[x][y] == 'X')
                                continue;
                            q.push(make_pair(x, y));
                            res.push_back(make_pair(x, y));
                            visit[x][y] = true;
                        }
                    }
                    if (flag) {
                        for (auto t : res)
                            board[t.first][t.second] = 'X';
                    }
                }
    }
};