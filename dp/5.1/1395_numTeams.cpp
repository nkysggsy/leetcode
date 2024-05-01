//
// Created by yesonggao on 2024/5/1.
//
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        int l[n][2], r[n][2]; // 0 less, 1 great
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        for (int i = 1; i + 1< n; i++) {
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) l[i][0]++;
                else if (rating[j] > rating[i]) l[i][1]++;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (rating[j] < rating[i]) r[i][0]++;
                if (rating[j] > rating[i]) r[i][1]++;
            }
            // cout << " L " << l[i][0] << " " << l[i][1] << endl;
            // cout << " R " << r[i][0] << " " << r[i][1] << endl;
        }
        for (int i = 1; i + 1 < n; i++)
            res += l[i][0] * r[i][1] + l[i][1] * r[i][0];
        return res;
    }
};