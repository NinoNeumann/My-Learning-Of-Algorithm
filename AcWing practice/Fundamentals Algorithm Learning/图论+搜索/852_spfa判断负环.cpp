//
// Created by Nino Neumann on 2023/3/6.
//
// 对比spfa计算负权值最短路径 多了一个cnt数组维护 从1到当前下表所代表的节点最短距离所经历的长度
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

const int N = 2e3+10;

struct node{
    int y,w;
};

struct head {
    vector<node> e;
};

head g[N];
bool st[N];
int dist[N];
int cnt[N];

int n,m;

bool spfa(){
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    for(int i = 1;i<=n;++i){
        q.push(i);
        st[i] = true;
    }

    while(!q.empty()){
        int t = q.front();
        q.pop();
        st[t] = false;
        if(cnt[t]==n) return true;
        for(auto x:g[t].e){
            if(dist[x.y]>dist[t]+x.w){
                dist[x.y] = dist[t]+x.w;
                cnt[x.y] = cnt[t]+1;
                if(!st[x.y]){
                    st[x.y] = true;
                    q.push(x.y);
                }

            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;++i){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].e.push_back({y,w});
    }

    if(spfa())cout<<"Yes";
    else cout<<"No";

    return 0;
}
