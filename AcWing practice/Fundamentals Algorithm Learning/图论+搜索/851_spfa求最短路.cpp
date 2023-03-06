//
// Created by Nino Neumann on 2023/3/6.
//
// bellman ford 不一定每次都会更新这条边

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int N = 1e5+10;

struct node{
    int o;
    int w;
};

struct head{
    vector<node> e;
};

head g[N];

int dist[N];
bool st[N];

int n,m;

void spfa(){
    // 初始化
    memset(dist,0x3f,sizeof dist);
    queue<int> q;
    dist[1] = 0;
    st[1] = true;
    q.push(1);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        st[t] = false;
        // 更新与t相关的所有的邻边如果更新了 且邻边不在队列中则加入队列  只有更新了距离的点才会更新其他与之相关的点
        for(auto x:g[t].e){
            int y = x.o,w = x.w;
            if(dist[y]>dist[t]+w){
                dist[y] = dist[t]+w;
                if(!st[y]){
                    q.push(y);
                    st[y] = true;
                }
            }
        }
    }


}




int main(){

    cin>>n>>m;
    while(m--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[x].e.push_back({y,z});
    }
    spfa();
    if(dist[n]==0x3f3f3f3f) cout<<"impossible";
    else cout<<dist[n];
    return 0;
}
