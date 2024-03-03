//
// Created by Nino Neumann on 2024/3/3.
//

class Solution {
public:
    bool f[1001][1001];
    string longestPalindrome(string s) {
        // c++ substr使用方法
        int start = 1, maxlen = 1;
        s = ' ' + s;
        for(int i = 0;i<s.size();++i) f[i][i] = true;
        for(int L = 2;L<s.size();++L){
            for(int i = 1;i<s.size();++i){
                int j = i+L-1;
                if(j>=s.size()) break;
                if(s[i]!=s[j]){
                    f[i][j] = false;
                }else{
                    if(L==2) f[i][j] = true;
                    else f[i][j] = f[i+1][j-1];
                }
                if(f[i][j] && j-i+1>maxlen){
                    start = i;
                    maxlen = j-i+1;
                }
            }
        }
        // cout<<maxlen<<endl;
        return s.substr(start,maxlen);
        // 最长公共子串
    }
};