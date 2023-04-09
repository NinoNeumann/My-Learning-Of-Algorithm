//
// Created by Nino Neumann on 2023/4/7.
//
// 思路，求最短路 最短路权重为乘法 且为最大的
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int N = 2010;

// 定义邻接表
struct edge{
    int o;
    int w;
};

struct head{
    vector<edge> e;
};
head heads[N];

double dist[N];
bool st[N];

int n,m;

void spfa(int s){
    queue<int> q;
    dist[s] = 1;
    st[s] = true;
    q.push(s);
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        st[x] = false;
        for(auto c:heads[x].e){
            int y = c.o;
            double w = (double)c.w/100;
            if(dist[y]<w*dist[x]){
                dist[y] = w*dist[x];
                // cout<<dist[y]<<endl;
                if(!st[y]){
                    q.push(y);
                    st[y] = true;
                }
            }
        }
    }
}


int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i<m;++i){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        w = 100 - w;
        heads[x].e.push_back({y,w});
        heads[y].e.push_back({x,w});
    }
    memset(dist,0xc2, sizeof dist);
    int x,y;
    scanf("%d%d",&x,&y);
    spfa(x);
    printf("%.8f",(double)100/dist[y]);

    return 0;
}

