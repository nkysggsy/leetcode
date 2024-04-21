//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        typedef long long LL;
        LL l = 1, r = 1e13 + 10;
        while (l < r) {
            LL m = l + (r - l) / 2;
            LL sum  = 0;
            for (int x : piles)
                sum += (x + m - 1) / m;
            if (sum <= h) r = m;
            else l = m + 1;
        }
        return l;
    }
};