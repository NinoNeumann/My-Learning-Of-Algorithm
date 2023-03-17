//
// Created by Nino Neumann on 2023/3/12.
//
// 基本框架三重循环
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N = 220;
const int INF = 0x7f7f7f7f;
int dp[N][N];
int n,m,q;


int main(){
    cin>>n>>m>>q;
    memset(dp,0x3f,sizeof dp);
    for(int i = 0;i<=n;++i) dp[i][i] = 0;
    for(int i = 0;i<m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        dp[x][y] = min(dp[x][y],z);
    }
    for(int k = 1;k<=n;++k){
        for(int i = 1;i<=n;++i)
            for(int j = 1;j<=n;++j){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(dp[x][y]>=INF/3)
            cout<<"impossible\n";
        else
            cout<<dp[x][y]<<endl;
    }

    return 0;
}