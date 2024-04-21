//
// Created by yesonggao on 2024/4/21.
//
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> indexs;
        for (int i = 0; i < nums2.size(); i++)
            indexs[nums2[i]] = i;

        int n = nums2.size();
        vector<int> nex(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                nex[s.top()] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        vector<int> res;
        for (int x: nums1)
            res.push_back(nex[indexs[x]]);
        return res;
    }
};