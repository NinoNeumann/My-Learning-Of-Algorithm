//
// Created by Nino Neumann on 2023/3/6.
//
// 存在负权值的单源最短路径
// for n 次
//      for 所有边 a b w
//          更新所有的边  dist b = min （dist b dist a + w）  【松弛操作】
//  循环之后所有边的距离 都满足三角不等式
//  存在负权回路 最短路不一定存在
//  迭代次数：经过不超过k条边到达点的距离   第n次如果有更新 则一定存在负环 （可以找负环）
//  计算最多不超过k条边所达的最短路径。这个只能用bellmanford算法
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 550;
struct edge{
    int x,y,w;
};

vector<edge> edges;
int dist[N],backup[N];

int n,m,k;
// bellman ford算法
/*
 * 1、算法可以计算最多经过多少条边后 （单源最短距离）
 * 2、出发点到其他边的最短距离 使用 dist数组记录
 * 3、dist数组初始化为 INF （因为你要求最短距离）
 * 4、我们需要的只是边
 * 5、经过最少k条边的k次循环后，
 * 6、memcpy dist 数组到backup
 * 7、遍历所有边 更新dist【y】距离 min(dist（backup）[x]+g[x][y],dist[y])
 *
 *
 * */

void bellman_ford(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 1;i<=k;++i){
        memcpy(backup,dist,sizeof dist);
        // 遍历所有的边
        for(auto e:edges){
            int x = e.x,y = e.y,w = e.w;
            dist[y] = min(dist[y],backup[x]+w);
        }
    }

    return dist[n];
}



int main(){
    cin>>n>>m>>k;
    for(int i = 0;i<=m;++i){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        edges.push_back({x,y,w});
    }
    bellman_ford();
    if(dist[n]>0x3f3f3f3f/4) cout<<"impossible"<<endl;
    else cout<<dist[n]<<endl;

    return 0;
}
