//
// Created by yesonggao on 2024/4/30.
//
class Solution {
public:
    typedef pair<int, int> II;
    II calc(string& str) {
        int x = 0, y = 0;
        for (char c : str) {
            if (c == '0') x++;
            else y++;
        }
        return pair<int,int>(x, y);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<II> nums;
        const int N = 610;
        int f[N][N] = {0};
        for (string& str: strs) {
            nums.push_back(calc(str));
        }
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i].first;
            int y = nums[i].second;
            for (int j = m; j >= x; j--)
                for (int k = n; k >= y; k--)
                    f[j][k] = max(f[j][k], f[j-x][k-y] + 1);
        }
        return f[m][n];
    }
};