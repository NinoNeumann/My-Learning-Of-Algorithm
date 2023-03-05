//
// Created by Nino Neumann on 2023/3/5.
//

/*
 * 初始化距离将dist 1  = 0 其他为一个无穷大
 * 迭代循环 0~n
 *      s：当前已经确定最短距离的点
 *      找最最短距离的点
 *
 * */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510;

int g[N][N];
bool st[N]; // 标记当前节点是否已经确定加入了最短路径
int dist[N];
int n,m;


int dijkstra(){
    // 初始化 将所有的距离初始化为正无穷
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;  // 起始点的距离为0；
    for(int i = 0;i<n;++i){ //循环n次每次智能找到1个点的距离 所以要循环n次来确定所有点的距离
        int t = -1;
        for(int j = 1;j<=n;++j){
            if(!st[j] && (t==-1 || dist[t]>dist[j])) t = j;
        }// 通过这个循环能确定当前没有被加入集合s且距离最小的点。
        st[t] = true;
        // 更新t有关的点
        for(int j = 1;j<=n;++j){
            dist[j] = min(dist[j],dist[t]+g[t][j]);
        }

    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    memset(g,0x3f,sizeof g);
    scanf("%d%d",&n,&m);
    while(m--){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        g[x][y] = min(g[x][y],w);
    }

    int k = dijkstra();

    cout<<k;
    return 0;
}
