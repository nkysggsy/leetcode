//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && nums[i] > nums[q.top()]) {
                res[q.top()] = i - q.top();
                q.pop();
            }
            q.push(i);
        }
        return res;
    }
};