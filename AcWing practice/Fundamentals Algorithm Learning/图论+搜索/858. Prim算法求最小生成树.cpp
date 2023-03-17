//
// Created by Nino Neumann on 2023/3/12.
//
#include<iostream>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 510;
int g[N][N];
bool st[N];
int dist[N];
int n,m;


int Prim(){
    // 初始化
    memset(dist,0x3f,sizeof dist);
    int res = 0; // 当前生成树的总长度
    for(int i = 0;i<n;++i){
        int t = -1; // 表示没有找到下一个目标点
        for(int j = 1;j<=n;++j)
            if(!st[j] && (t==-1 || dist[t]>dist[j])) t = j;

        if(i && dist[t]==INF) return INF; // 点没有被完全遍历完就遇到了当前最近的点是INF的情况也就是说当前图不连通
        if(i) res += dist[t];
        st[t] = true;


        for(int j = 1;j<=n;++j){
            dist[j] = min(dist[j],g[t][j]);
        }
    }
    return res;
}

int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    while(m--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[x][y] = min(g[x][y],z);
        g[y][x] = g[x][y];
    }
    int t = Prim();

    if(t==INF)
        cout<<"impossible\n";
    else
        cout<<t<<endl;

    return 0;
}