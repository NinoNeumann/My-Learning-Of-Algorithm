//
// Created by Nino Neumann on 2023/3/6.
//
// 思路：三重循环
#include<iostream>
using namespace std;

const int N = 110;


int f[N][N];
int v[N],w[N],k[N];
int n,m;


int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        cin>>v[i]>>w[i]>>k[i];
    }

    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            f[i][j] = f[i-1][j];
            if(j>v[i]){
                for(int d = 0;d<=k[i];++d){
                    if(j>d*v[i]){
                        f[i][j] = max(f[i][j],f[i-1][j-d*v[i]]+d*w[i]);
                    }
                }
            }
        }
    }
    cout<<f[n][m];




}