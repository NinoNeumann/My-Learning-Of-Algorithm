//
// Created by Nino Neumann on 2023/3/6.
//
// 求指挥部到所有哨所的最短路径中的最大值
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int,int> PII;
const int N = 110;
struct node{
    int y,w;
};

struct head{
    vector<node> e;
};

head g[N];
int dist[N];
bool st[N];

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
        for(auto edge:g[idx].e){
            if(dist[edge.y]>distance+edge.w){
                dist[edge.y] = distance+edge.w;
                heap.push({dist[edge.y],edge.y});
            }
        }
    }
    // 找所有最短路径中的最大值
    int mx = -1;
    for(int i = 1;i<=n;++i)mx = max(mx,dist[i]);
    if(mx==0x3f3f3f3f) return -1;
    return mx;

}


int main(){
    cin>>n>>m;
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].e.push_back({y,z});
        g[y].e.push_back({x,z});
    }

    int k = dijkstra();
    cout<<k;
    return 0;
}
