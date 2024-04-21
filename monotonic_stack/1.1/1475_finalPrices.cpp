//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> dis(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && prices[i] <= prices[s.top()]) {
                dis[s.top()] = prices[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < n; i++)
            prices[i] -= dis[i];

        return prices;
    }
};