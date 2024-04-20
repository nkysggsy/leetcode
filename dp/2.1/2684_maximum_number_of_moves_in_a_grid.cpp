//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int MAX = 1e6;
        vector<vector<int>> grid2;
        grid2.push_back(vector<int>(n, MAX));
        grid2.insert(grid2.end(), grid.begin(), grid.end());
        grid2.push_back(vector<int>(n, MAX));
        int f[m+2][n];
        memset(f, 0, sizeof(f));

        int ans = 0;
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m + 1; i++) {
                //  cout << i << " " << j << endl;
                if (f[i-1][j-1] >= 0 && grid2[i][j] > grid2[i-1][j-1]) {
                    //  cout << "i-1, j-1 " << i << " " << j << endl;
                    f[i][j] = max(f[i][j], f[i-1][j-1] + 1);

                }
                if (f[i][j-1] >= 0 && grid2[i][j] > grid2[i][j-1]) {
                    //  cout << "i, j-1 " << i << " " << j <<endl;
                    f[i][j] = max(f[i][j], f[i][j-1] + 1);
                }
                if (f[i+1][j-1] >= 0 && grid2[i][j] > grid2[i+1][j-1]) {
                    //  cout << "i+1, j-1 " << i << " " << j << endl;
                    f[i][j] = max(f[i][j], f[i+1][j-1] + 1);
                }
                if (f[i][j] == 0) {
                    f[i][j] = -1;
                    // cout << i << " " << j << " " << f[i][j] << endl;
                }
                ans = max(ans, f[i][j]);
            }
        }
        return ans;
    }
};