//
// Created by yesonggao on 2024/5/6.
//
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1);
        typedef long long LL;
        unordered_map<int, LL> hashs;
        hashs[0] = 1;
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] ^ nums[i - 1];
            ans += hashs[sums[i]];
            hashs[sums[i]]++;
        }
        return ans;
    }
};