//
// Created by Nino Neumann on 2024/3/3.
//
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> f(s.size()+1,false);
        unordered_set<string> map;
        int n = s.size();

        s = ' ' + s;
        f[0] = true;
        for(auto word:wordDict) map.insert(word);

        for(int i = 1;i<=n;++i)
            for(int j = 1;j<=i;++j)
                if(f[j-1] && map.find(s.substr(j,i-j+1))!=map.end()) f[i] = true;

        return f[n];
    }
};