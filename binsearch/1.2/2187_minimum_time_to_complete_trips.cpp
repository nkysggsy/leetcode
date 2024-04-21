//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0, r = 1e14 + 10;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            long long sum = 0;
            for (int num : time)
                sum += mid / num;
            if (sum >= totalTrips)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};