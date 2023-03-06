//
// Created by Nino Neumann on 2023/3/6.
//
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int f[m+1][n+1];
        memset(f,0,sizeof f);
        // 边界条件判断
        if(obstacleGrid[0][0]) return 0;
        // 这题比较坑的是（对我来说）对f数组的初始化
        for(int i = 1;i<=m;++i){
            if(obstacleGrid[i-1][0])break;
            f[i][1] = 1;
        }
        for(int j = 1;j<=n;++j){
            if(obstacleGrid[0][j-1])break;
            f[1][j] = 1;
        }
        for(int i = 1;i<=m;++i)
            for(int j = 1;j<=n;++j){
                if(obstacleGrid[i-1][j-1])continue;
                f[i][j] = max(f[i][j],f[i-1][j]+f[i][j-1]);
            }
        return f[m][n];
    }
};