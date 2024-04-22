//
// Created by yesonggao on 2024/4/22.
//
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> f(n + 1, 0);
        f[0] = -1;
        for (int i = 1; i <= n; i++)
            f[i] = i - 1;

        for (int i = 0; i < n + 1; i++)
            for (int j = i + 1; j < n + 1; j++) {

                bool ret = check(s, i, j-1);
                //   cout << i << " " << j - 1 << " " << ret << endl;
                if (ret) {
                    // cout << "f[" << j << "] " << f[j] << " f[" << i << "] " << f[i] << endl;
                    f[j] = min(f[j], f[i] + 1);
                }
            }

        return f[n];
    }

    bool check(string& s, int i, int j) {
        for (; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};