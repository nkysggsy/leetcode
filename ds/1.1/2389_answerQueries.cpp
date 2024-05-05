//
// Created by yesonggao on 2024/5/5.
//
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];

        vector<int> ans;
        for (int x : queries) {
            int l = 0, r = n;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (nums[m] > x) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            ans.push_back(l);
        }
        return ans;
    }
};