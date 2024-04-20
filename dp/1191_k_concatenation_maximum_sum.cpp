//
// Created by yesonggao on 2024/4/20.
//
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        typedef long long LL;
        const int MOD = 1e9 + 7;
        // ai +... + aj == ans_max, ai + .... + aj == ans_min
        LL sum = 0, pre_min = 0, ans_max = 0, ans_max2 = 0;
        for (int x : arr) {
            sum += x;
            ans_max = max(ans_max, sum - pre_min);
            pre_min = min(pre_min, sum);
        }
        LL sum2 = 0, pre_min2 = 0;

        for (int i = 0; i < 2;i++) {
            for (int x: arr) {
                sum2 += x;
                ans_max2 = max(ans_max2, sum2 - pre_min2);
                pre_min2 = min(pre_min2, sum2);
            }
        }
        if (k == 1) {
            return ans_max % MOD;
        }
        if (sum > 0) {
            LL val = max(sum * (k - 1) + ans_max, sum * (k - 2) + ans_max2);
            return val % MOD;
        } else if (sum == 0)  {
            return max(ans_max, ans_max2) % MOD;
        } else {
            return max(ans_max, ans_max2) % MOD;
        }

    }
};