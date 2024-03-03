//
// Created by Nino Neumann on 2024/3/3.
//

// 使用dp进行预处理 + dfs(回溯) 分割整个字符串 详见5.最长回文子串
// 难点：1 比较难想到吧 2、dfs如何不重不漏地分割整个字符串

class Solution {
public:
    bool f[18][18];
    vector<vector<string>> res;
    vector<string> ans;
    int n;

    void split(const string s,int i){
        if(i>n){
            res.push_back(ans);
            return;
        }
        for(int j = i;j<=n;++j){
            if(f[i][j]){
                ans.push_back(s.substr(i,j-i+1));
                split(s,j+1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        n = s.size();
        s = ' ' + s;
        for(int i = 1;i<=n;++i) f[i][i] = true;
        for(int L = 2;L<=n;++L){
            for(int i = 1;i<=n;++i){
                int j = i+L-1;
                if(j>n) break;
                if(s[i]==s[j]){
                    if(L==2) f[i][j] = true;
                    else f[i][j] = f[i+1][j-1];
                }else{
                    f[i][j] = false;
                }
            }
        }

        split(s,1);

        return res;
    }
};
