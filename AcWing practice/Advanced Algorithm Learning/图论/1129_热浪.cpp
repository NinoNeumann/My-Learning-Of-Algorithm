//
// Created by Nino Neumann on 2023/3/6.
//

// 一些信息： 除了起点和终点外的每个城镇都由 双向道路 连向至少两个其它的城镇
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int,int> PII;
const int N = 2600;

struct node{
    int y,w;
};
struct head{
    vector<node> e;
};

head g[N];

bool st[N];
int dist[N];

int T,C,T_s,T_e;

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[T_s] = 0;
    st[T_s] = true; // 不需要将初始的点设置成true 设置了也无所谓 [bushi] 千万不能在初始化的时候设置T——s的状态为true
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,T_s});
    while(!heap.empty()){

        auto t = heap.top();
        heap.pop();

        int idx = t.second,distance = t.first;
        if(st[idx]) continue;
        st[idx] = true;
        for(auto edge:g[idx].e){
            if(dist[edge.y]>distance+edge.w){
                // 更新节点对应的距离并将这个节点加入heap中
                dist[edge.y] = distance+edge.w;
                heap.push({dist[edge.y],edge.y});
            }
        }
    }
    return dist[T_e];
}

int main(){
    cin>>T>>C>>T_s>>T_e;
    while(C--){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].e.push_back({y,w});
        if(x!=T_s && y!=T_e)
            g[y].e.push_back({x,w});
    }

    int k = dijkstra();
    cout<<k;
    return 0;
}


