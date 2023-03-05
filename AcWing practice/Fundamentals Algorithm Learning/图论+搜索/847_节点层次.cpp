//
// Created by Nino Neumann on 2023/3/4.
//
//思路 广度优先遍历  关键用一个st数组记录当前点到1点的距离并且初始化-1
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int N = 1e5+10;

struct head{
    vector<int> chain;
};

head graph[N];
int st[N];
//int dis[N]; // 记录每个节点到
int n,m; // n节点个数 m 边数

int bfs(int node,bool& find){
    queue<int> q;
    q.push(node);
    st[node] = 0;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto next:graph[f].chain){
            if(st[next]!=-1)continue; // 如果下一个即将遍历的节点被访问过了 就继续
            st[next] = st[f]+1;
            q.push(next);
        }
    }
    return d[n];

}


int main(){
    bool find = false;
    memset(st,-1,sizeof st);
    scanf("%d%d",&n,&m);
    for(int i = 0;i<m;++i){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        graph[t1].chain.push_back(t2);
    }
    cout<<d[n];

    return 0;
}


