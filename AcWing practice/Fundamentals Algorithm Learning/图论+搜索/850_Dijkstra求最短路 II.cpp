//
// Created by Nino Neumann on 2023/3/5.
//
// 堆优化版的
// 优化点：每次循环找最小值的操作可以做优化
//       每次修改数值的点  的复杂度为log n
//      使用堆可以让

// 手写堆
// 使用优先队列  priority_queue  不支持修改任意一个元素的操作 （好写）
// 存储方式改成邻接表
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int,int> PII;
const int N = 1e5+10;
const int INF = 0x3f3f3f3f;
// 构建邻接表
struct node{
    int o,w;
};
struct head{
    vector<node> e;
};
head g[N];
bool st[N];
int dist[N];
int n,m;

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(!heap.empty()){
        auto t = heap.top();
        heap.pop();
        int idx = t.second,distance = t.first;
        if(st[idx]) continue;
        st[idx] = true;
        // 更新idx对应的一些点的距离
        for(auto nd:g[idx].e){
            // 更新当前最短路径将可更新点加入堆中
            if(dist[nd.o]>distance+nd.w){
                dist[nd.o] = distance+nd.w;
                heap.push({dist[nd.o],nd.o});
            }
        }
    }
    if(dist[n]==INF)return -1;
    return dist[n];
}
// 普通版 dijkstra算法
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 0;i<n;++i){
        int t = -1;
        for(int j = 1;j<=n;++j)
            if(!st[j] && (t==-1 || dist[t]>dist[j])) t = j;
            st[t] = true;
        for(auto x:g[t].e){
            dist[x.o] = min(dist[x.o],dist[t]+x.w);
        }
//            for(int j = 1;j<=n;++j){
//                dist[j] = min(dist[j],dist[t]+w[t]);  // w[t]
//            }
    }
    if(dist[n]==INF) return -1;
    return dist[n];

}


int main(){
    cin>>n>>m;
    while(m--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[x].e.push_back({y,z});
    }

    int k = dijkstra();
    cout<<k<<endl;



    return 0;
}

