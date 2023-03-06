//
// Created by Nino Neumann on 2023/3/6.
//
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 和62题的套路一样
        int n = grid.size();
        int m = grid[0].size();
        int f[n+1][m+1];
        memset(f,0,sizeof f);
        // 初始化
        for(int i = 1;i<=n;++i)
            f[i][1] = f[i-1][1] + grid[i-1][0];
        for(int j = 1;j<=m;++j)
            f[1][j] = f[1][j-1] + grid[0][j-1];
        for(int i = 2;i<=n;++i){
            for(int j = 2;j<=m;++j){
                f[i][j] = min(f[i-1][j],f[i][j-1])+grid[i-1][j-1];
            }
        }
        return f[n][m];
    }
};