//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N = 1e3 + 10;
        int n = cost.size();
        int f[N] = {0};
        for (int i = 2; i <= n; i++) {
            f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
        }
        return f[n];
    }
};