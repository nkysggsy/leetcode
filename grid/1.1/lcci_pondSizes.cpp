//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        vector<int> ans;
        typedef pair<int, int> PII;
        int dx[] = {0, 0, 1, -1, -1, 1, 1, -1};
        int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!land[i][j]) {
                    int cnt = 0;
                    queue<PII> q;
                    q.push(make_pair(i, j));
                    land[i][j] = -1;
                    while (!q.empty()) {
                        auto t = q.front();
                        q.pop();
                        cnt++;
                        for (int k = 0; k < sizeof(dx) / sizeof(dx[0]); k++) {
                            int x = t.first + dx[k];
                            int y = t.second + dy[k];
                            if (x < 0 || x >= m || y < 0 || y >= n ||
                                land[x][y])
                                continue;
                            q.push(make_pair(x, y));
                            land[x][y] = -1;
                        }
                    }
                    ans.push_back(cnt);
                }
        sort(ans.begin(), ans.end());
        return ans;
    }
};