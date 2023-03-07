//
// Created by Nino Neumann on 2023/3/6.
//
/*
 *
 * 状态表示 f ij  表示
 *
 *
 *
 * */

#include <iostream>
using namespace std;

const int N = 1010;

int n,m;
int v[N],w[N];  // 每种都不一样
int f[N][N];


int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
         cin>>v[i]>>w[i];
    // 二维版本：
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(j<v[i]) f[i][j] = f[i-1][j];
            // 通过状态转移方程以及其前一项的公式可以将原有的公式化简
            else f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]);
        }
    }
    cout<<f[n][m]<<endl;
    // 一维化简版


    return 0;
}