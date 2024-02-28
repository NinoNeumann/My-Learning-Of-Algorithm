//
// Created by Nino Neumann on 2024/2/28.
//
#include<iostream>
using namespace std;

const int N = 101;

int G[N][N];
int f[N][N];

int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=n;++j)
            cin>>G[i][j];

    // 需要初始化
    for(int i = 1;i<=n;++i) f[1][i] = f[1][i-1] + G[1][i], f[i][1] = f[i-1][1] + G[i][1];

    for(int i = 2;i<=n;++i)
        for(int j = 2;j<=n;++j)
            f[i][j] = min(f[i-1][j],f[i][j-1])+G[i][j];
    cout<<f[n][n];
    return 0;
}