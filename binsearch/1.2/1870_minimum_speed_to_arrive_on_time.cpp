//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e9 + 10;
        while (l < r) {
            int m = l + (r - l) / 2;
            double sum = 0;
            for (int i = 0; i  + 1 < dist.size(); i++) {
                sum += (dist[i] + m - 1) / m;
            }
            sum += dist.back() * 1.0 / m;
            if (sum <= hour)
                r = m;
            else
                l = m + 1;
        }
        return l == (1e9 + 10) ? -1 : l;
    }
};