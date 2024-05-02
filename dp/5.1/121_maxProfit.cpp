//
// Created by yesonggao on 2024/5/2.
//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int pre_min = 1e4;
        for (auto x : prices) {
            ans = max(ans, x - pre_min);
            pre_min = min(x, pre_min);
        }
        return ans;
    }
};