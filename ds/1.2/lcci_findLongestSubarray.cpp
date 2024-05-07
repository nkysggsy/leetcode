//
// Created by yesonggao on 2024/5/7.
//
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        vector<int> sums(n + 1);
        unordered_map<int, int> hashs;
        hashs[0] = -1;
        int len = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + (isdigit(array[i][0]) ? 1 : -1);
            if (hashs.contains(sums[i + 1])) {
                if (len < i - hashs[sums[i + 1]]) {
                    len = i - hashs[sums[i + 1]];
                    start = hashs[sums[i + 1]];
                }
            } else
                hashs[sums[i + 1]] = i;
        }
        if (!len)
            return vector<string>();
        return {array.begin() + start +1, array.begin() + len + 1 + start};
    }
};