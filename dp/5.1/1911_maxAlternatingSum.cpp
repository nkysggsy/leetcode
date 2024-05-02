//
// Created by yesonggao on 2024/5/3.
//
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        typedef long long LL;
        const int N = 1e5 + 10;
        // 0 negative，1 positive
        LL f[N][2];
        f[0][0] =  -1e10;
        f[0][1] = nums[0];
        LL ans = 0;
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i-1][0],max(0LL,f[i-1][1]) - nums[i]);
            f[i][1] = max(f[i-1][1], max(0LL,f[i-1][0]) + nums[i]);
        }
        return max(f[n-1][0], f[n-1][1]);
    }
};