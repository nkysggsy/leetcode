//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        const int MAX = 25e6 + 10;
        int l = 0, r = MAX;
        int n = weights.size();
        for (int x : weights)
            l = max(l, x);

        while (l < r) {
            int mid = l + (r - l) / 2;
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (sum + weights[i] > mid) {
                    sum = 0;
                    cnt++;
                }
                sum += weights[i];
            }
            cnt++;
            if (cnt <= days) {
                r = mid;
            } else
                l = mid + 1;
        }
        return l;
    }
};