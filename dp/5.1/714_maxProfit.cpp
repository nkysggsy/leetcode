//
// Created by yesonggao on 2024/5/2.
//
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        const int N = 5 * 1e4 + 10;
        // 0 sell, 1 buy
        int f[N][2] = {0};
        f[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i-1][0], f[i-1][1] + prices[i] - fee);
            f[i][1] = max(f[i-1][1], f[i-1][0] - prices[i]);
        }
        return f[n-1][0];
    }
};