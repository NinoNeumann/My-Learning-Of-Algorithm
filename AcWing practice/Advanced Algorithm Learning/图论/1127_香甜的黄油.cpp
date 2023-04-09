//
// Created by Nino Neumann on 2023/3/6.
//
// 思路 Dijkstra
/*
 * 对每一个点求一遍dijkstra 然后计算其到其他所有有奶牛的牧场的距离之和
 * N<=500 复杂度为o^3 125*10^6; 超时 得使用堆优化版本的dijkstra
 * 数据保证该图必定是联通的。
 *
 *
 * */
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 900+10;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;

struct node{
    int o,w;
};
struct head{
    vector<node> e;
};
head heads[N];

bool st[N];
int dist[N];
int cows[N]; // 下标为i的牧场所拥有的奶牛数量

int n,p,c;  // n奶牛数量 p 牧场数量 c 边数量


int Dijkstra(int start){
    int res = 0;
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[start] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,start});
    while(!heap.empty()){
        auto t = heap.top();
        heap.pop();
        int idx = t.second, dis = t.first;
        if(st[idx]) continue;
        st[idx] = true;
        // 更新和该点有关的所有的边的dist
        for(auto edge:heads[idx].e){
            if(dist[edge.o]>edge.w+dis){
                dist[edge.o] = edge.w+dis;
                heap.push({dist[edge.o],edge.o});
            }
        }
    }
    for(int i = 1;i<=n;++i){
        if(dist[cows[i]]==INF) return INF;
        res+=dist[cows[i]];
    }
    return res;
}


int main(){
    cin>>n>>p>>c;  // p相当于节点数量
    for(int i = 1;i<=n;++i){
        cin>>cows[i];
    }
    // memset(g,0x3f,sizeof g);
    for(int i = 0;i<c;++i){
        int x,y,z;
        cin>>x>>y>>z;
        heads[x].e.push_back({y,z});
        heads[y].e.push_back({x,z});
    }
    int min_dist = INF;
    for(int i = 1;i<=p;++i){
        min_dist = min(min_dist,Dijkstra(i));
    }
    cout<<min_dist<<endl;

    return 0;
}


