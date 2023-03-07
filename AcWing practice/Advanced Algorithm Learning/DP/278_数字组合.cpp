//
// Created by Nino Neumann on 2023/3/3.
//
// 感觉可以dfs bushi  时间复杂度太高了 舍弃 2^100
// 状体表示fij 表示从i到j个字母能够组成和为M的所有组合的集合 【x】 不可行 我想不出来如何递推 不需要二维表示数组范围
// fij表示前i个数字之和恰好为j的集合
// 01背包求方案数量
#include<iostream>
using namespace std;

const int N = 11000;

int g[N],f[N][N];
int n,m;

int main(){
    // 输入
    cin>>n>>m;
    for(int i = 1;i<=n;++i)cin>>g[i];
    // 初始化这边没懂

    f[0][0] = 1;
    for(int i = 1;i<=n;++i){
        // 二维的思维
        for(int j = 0;j<=m;++j){
            // 当前 fij可以被划分为两个子集合 即包含物品i的集合和不包含物品i的集合 计算方法就是相加
            f[i][j] = f[i-1][j];
            if(j>=g[i]) f[i][j] += f[i-1][j-g[i]];

        }
//        for(int j = m;j>=g[i];--j)
//            f[j] = max(f[j],f[j-g[i]]+1);
    }
    cout<<f[n][m]<<endl;
    return 0;
}