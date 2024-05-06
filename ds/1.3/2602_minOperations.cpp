//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        typedef long long LL;
        vector<LL> sums(n + 1);
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];

        int m = queries.size();
        vector<LL> ans(m);
        for (int i = 0; i < m; i++) {
            int x = queries[i];
            if (x <= nums[0]) {
                ans[i] = sums[n] - 1LL * n * x;
            } else if (x >= nums.back()) {
                ans[i] = 1LL * n * x - sums[n];
            } else {
                int l = 0, r = n;
                while (l < r) {
                    int m = l + (r - l) / 2;
                    if (nums[m] > x)
                        r = m;
                    else
                        l = m + 1;
                }
                ans[i] =
                        1LL * l * x - 2 * sums[l] + sums[n] - 1LL * (n - l) * x;
            }
        }
        return ans;
    }
};