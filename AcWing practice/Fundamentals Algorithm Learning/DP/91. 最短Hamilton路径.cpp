//
// Created by Nino Neumann on 2023/3/7.
//
// 考虑的时候用一种贪心的思想
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 20;
const int M = 1<<N;

int f[M][N]; // fij 表示在i的状态下 结尾是j个点的路径的集合  属性是距离的最小值
             // 运算：f[state,j] = f[state_k,k] + weight[k][j]  : state_k 是state不包含j 且包含k的版本
             // 判定合法状态
int g[N][N];
int n;


int main(){
    cin>>n;
    for(int i = 0;i<n;++i)
        for(int j = 0;j<n;++j)
            cin>>g[i][j];

    memset(f,0x3f,sizeof f);
    f[1][0] = 0;

    for(int state = 0;state < 1 << n; ++state){
        for(int j = 0;j<n;++j)
            if((state>>j)&1)
                for(int k = 0;k<n;++k){
                    int state_k = (state-(1<<j));
                    if((state_k>>k) & 1)
                        f[state][j] = min(f[state][j],f[state_k][k]+g[k][j]);
                }
    }
    cout<<f[(1<<n)-1][n-1];



    return 0;
}

