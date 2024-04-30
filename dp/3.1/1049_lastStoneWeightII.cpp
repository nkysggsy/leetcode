//
// Created by yesonggao on 2024/4/30.
//
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int x : stones)
            sum += x;
        int ans = 100;
        const int N = 3010;
        int f[N] = {0};
        for (int i = 0; i < stones.size(); i++)
            for (int j = sum; j >= stones[i]; j--) {
                f[j] = max(f[j], f[j- stones[i]] + stones[i]);
                ans = min(ans, abs(sum - 2 * f[j]));
                if (ans == 0) return ans;
            }
        return ans;
    }
};