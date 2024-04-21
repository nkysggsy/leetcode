//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        typedef long long LL;
        int n = bloomDay.size();
        if (n * 1LL < 1LL * m * k) return -1;
        int l = 1 , r = 1e9 + 10;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0, nums = 0;
            for (int i = 0; i < n; ) {
                cnt = 0;
                if (bloomDay[i] <= mid) {
                    while (i < n && bloomDay[i] <= mid && cnt < k) {
                        cnt++;
                        i++;
                    }
                    if (cnt >= k) nums++;
                }
                else {
                    i++;
                }
            }
            if (nums >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};