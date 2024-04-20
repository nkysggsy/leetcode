//
// Created by yesonggao on 2024/4/20.
//
class Solution {
private:
    unordered_map<int, int> cache;
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }
        cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return cache[n];
    }
};