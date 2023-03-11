//
// Created by Nino Neumann on 2023/3/11.
//
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        int f[matrix.size()+1][matrix[0].size()+1]; // 定义fij为左下角坐标为ij的正方形的边长 属性：最大值
        // 递推的话只要看其左上角、正上方、左方的数字
        memset(f,0,sizeof f);

        int mx = 0;
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(matrix[i][j]=='1'){
                    if(i==0 || j==0){
                        f[i][j]=1;
                    }else{
                        f[i][j] = min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
                    }
                }
                mx = max(mx,f[i][j]);
            }
        }
        return mx*mx;
    }
};