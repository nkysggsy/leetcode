//
// Created by yesonggao on 2024/5/6.
//
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int start = 0;
        const int MOD = 1e9 + 7;
        while (n) {
            if (n & 1)
                powers.push_back(start);
            n = n >> 1;
            start++;
        }
        vector<int> sums(powers.size() + 1);
        for (int i = 1; i < sums.size(); i++)
            sums[i] = sums[i - 1] + powers[i - 1];

        vector<int> ans;
        for (vector<int> q : queries) {
            int res = pomod(sums[q[1] + 1] - sums[q[0]], MOD);
            ans.push_back(res);
        }
        return ans;
    }

    int pomod(int n, int MOD) {
        typedef long long LL;
        LL val = 1;
        LL mul = 2;

        while (n) {
            if (n & 1)
                val = val * mul % MOD;
            mul = mul * mul % MOD;
            n = n >> 1;
        }
        return val % MOD;
    }
};