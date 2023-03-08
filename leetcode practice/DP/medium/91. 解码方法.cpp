//
// Created by Nino Neumann on 2023/3/7.
//
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int f[n+1];
        memset(f,0,sizeof f);

        f[0] = 1;

        for(int i = 1;i<=n;++i){
            // int k = ;
            if(s[i-1]!='0')f[i] += f[i-1];
            if(i>=2 &&  s[i-2]!='0' && stoi(s.substr(i-2,2))<=26 ){
                f[i] += f[i-2];
            }

        }
        return f[n];
    }
};