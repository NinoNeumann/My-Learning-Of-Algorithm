//
// Created by Nino Neumann on 2023/3/7.
//
// https://leetcode.cn/problems/interleaving-string/solutions/335373/jiao-cuo-zi-fu-chuan-by-leetcode-solution/ 很赞的思路

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())return false;
        int n = s1.length();
        int m = s2.length();
        int f[n+1][m+1];
        memset(f,0,sizeof f);
        f[0][0] = 1;
        for(int i = 0;i<=n;++i){
            for(int j = 0;j<=m;++j){
                int p = i + j - 1;
                if (i > 0 && s1[i - 1] == s3[p]) {
                    f[i][j] |= (f[i - 1][j] );
                }
                if (j > 0 && s2[j - 1] == s3[p]) {
                    f[i][j] |= (f[i][j - 1] );
                }

            }
        }
        return f[n][m];
    }
};