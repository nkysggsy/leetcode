//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    typedef long long LL;
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<LL> ans(n);
        unordered_map<int, vector<int>> hashs;
        for (int i = 0; i < n; i++)
            hashs[nums[i]].push_back(i);

        for (auto it = hashs.begin(); it != hashs.end(); it++) {
            set(it->second, ans);
        }
        return ans;
    }

    void set(vector<int>& vals, vector<LL>& ans) {
        int n = vals.size();
        if (!n)
            return;
        vector<LL> sums(n + 1);
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + vals[i];

        for (int i = 0; i < n; i++)
            ans[vals[i]] = 1LL * (i - 1) * vals[i] - 2 * sums[i] + sums[n] -
                           1LL * (n - 1 - i) * vals[i];
    }
};