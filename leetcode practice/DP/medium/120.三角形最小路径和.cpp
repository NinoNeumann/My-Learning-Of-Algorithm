//
// Created by Nino Neumann on 2024/3/3.
// 经典三角形dp问题
class Solution {
        public:
        int f[201][201];
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size(); // 行数量
            int m = triangle[0].size(); // 列数量
            for(int i = n-1;i>=0;--i){
                for(int j = 0;j<=i;++j){
                    f[i][j] = min(f[i+1][j],f[i+1][j+1])+triangle[i][j];
                    // cout<<f[i][j];
                }

            }
            return f[0][0];
        }
};