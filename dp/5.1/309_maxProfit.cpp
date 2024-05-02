//
// Created by yesonggao on 2024/5/2.
//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        const int N = 5e3 + 10;
        int f[N][3] = {0};
        f[0][1] = -prices[0];

        // 0 sell, 1 buy, 2 cooldown
        for (int i = 1; i < n; i++) {
            f[i][1] = max(f[i-1][1], f[i-1][2] - prices[i]);
            f[i][2] = max(f[i-1][2], f[i-1][0]);
            f[i][0] = f[i-1][1] + prices[i];
        }
        return max(f[n-1][0], f[n-1][2]);
    }
};