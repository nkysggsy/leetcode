//
// Created by yesonggao on 2024/5/5.
//
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> sums(n + 1, 0);
        const int MOD = 1e9 + 7;
        int caches[2] = {1, 0};
        caches[0] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            sums[i] = (sums[i - 1] + arr[i - 1]) % 2;
            ans += sums[i] ? caches[0] : caches[1];
            ans = ans % MOD;
            caches[sums[i]]++;
        }
        return ans % MOD;
    }
};