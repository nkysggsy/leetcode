//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());

        stack<int> s;
        vector<int> res(2 * n, -1);
        for (int i = 0; i < 2 * n; i++) {
            while (!s.empty() && nums[i] > nums[s.top()]) {
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        return vector<int>(res.begin(), res.begin() + n);
    }
};