//
// Created by yesonggao on 2024/5/2.
//
class Solution {
public:
    int longestString(int x, int y, int z) {
        const int VAL_MIN = -2e4;
        int f[x + 1][y + 1][z + 1][3];
        // status 0 x, status 1 y, status 2 z
        memset(f, -0x3f, sizeof(f));
        // yx -> BBAA
        f[1][1][0][0] = 4;
        // xy -> AABB
        f[1][1][0][1] = 4;
        // zx -> ABAA
        f[1][0][1][0] = 4;
        // xz -> AAAB
        f[1][0][1][2] = VAL_MIN;
        // zy -> ABBB
        f[0][1][1][1] = VAL_MIN;
        // yz -> BBAB
        f[0][1][1][2] = 4;
        int ans = 0;

        for (int i = 1; i <= x; i++)
            for (int j = 1; j <= y; j++)
                for (int k = 1; k <= z; k++) {
                    f[i][j][k][0] = max(f[i-1][j][k][1] + 2, f[i-1][j][k][2]+2);
                    f[i][j][k][1] = f[i][j-1][k][0] + 2;
                    f[i][j][k][2] =  max(f[i][j][k-1][1] + 2, f[i][j][k-1][2] + 2);
                    ans = max(ans, max(max(f[i][j][k][0], f[i][j][k][1]), f[i][j][k][2]));
                }
        return ans;
    }
};