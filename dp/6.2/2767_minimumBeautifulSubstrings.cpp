//
// Created by yesonggao on 2024/5/4.
//
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        if (s[0] == '0') return -1;
        set<string> strs;
        int num = 1;
        for (int i = 1; i <= 7; i++) {
            string str;
            int n = num;
            while (n) {
                str += n % 2 + '0';
                n = n >> 1;
            }
            reverse(str.begin(),str.end());
            strs.insert(str);
            //  cout << str << endl;
            num *= 5;
        }
        int n = s.size();
        vector<int> f(n+1, 2e5);
        f[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++) {
                if (strs.contains(s.substr(j, i - j))) {
                    // cout << "YSG " << s.substr(j, i - j) << endl;
                    f[i] = min(f[i], f[j] + 1);
                }
            }

        //   cout << f[3] << endl;
        return f[n] >= 1e5 ? -1 : f[n];
    }
};