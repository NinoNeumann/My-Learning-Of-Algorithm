//
// Created by Nino Neumann on 2023/3/8.
//
#include<iostream>
#include<cstring>
using namespace std;

const int N = 330;

int g[N][N];
int f[N][N];
int dis_x[]={0,-1,0,1};
int dis_y[]={-1,0,1,0};
int n,m;


int dp(int x,int y){
    int &v = f[x][y];
    if(v!=-1) return v;
    v = 1;
    for(int k = 0;k<4;++k){
        int d_x = x+dis_x[k],d_y = y+dis_y[k];
        if(d_x<=0 || d_y<=0 || d_x>n || d_y>m) continue;
        if(g[d_x][d_y]>=g[x][y]) continue;
        v = max(v,dp(d_x,d_y)+1);
    }
    return v;
}

int main(){
    cin>>n>>m;

    memset(f,-1,sizeof f);
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            cin>>g[i][j];
        }
    }
    int mx = 0;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            // 遍历四个方向从中找到小于其的高度的最长的那个点 并将自己的最长距离++
            // 这里需要用递归方式去计算 （相当于dfs） 当前位置 ij 所能下降的最远距离
            // for(int k = 0;k<4;++k){
            //     int d_x = i+dis_x[k],d_y = j+dis_y[k];
            //     if(d_x<0 || d_y<0 || d_x>n || d_y>m) continue;
            //     if(g[d_x][d_y]>=g[i][j]) continue;
            //     f[i][j] = max(f[i][j],f[d_x][d_y]+1);
            // }
            // mx = max(mx,f[i][j]);
            mx = max(mx,dp(i,j));
        }
    }
    cout<<mx;

    return 0;
}