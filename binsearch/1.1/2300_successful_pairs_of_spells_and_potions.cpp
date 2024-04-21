class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        typedef long long LL;
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int x : spells) {
            int l = 0, r = potions.size();
            while (l < r) {
                int m = l + (r - l) / 2;
                if (1LL * x * potions[m] >= success)
                    r = m;
                else
                    l = m + 1;
            }
            res.push_back( potions.size() - l);
        }
        return res;
    }
};