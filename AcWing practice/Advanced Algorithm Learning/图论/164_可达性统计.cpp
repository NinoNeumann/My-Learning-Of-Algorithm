//
// Created by Nino Neumann on 2023/3/5.
//
// 思路一：在对原图的逆拓图进行排序的时候直接进行一个可达边的累计（不可行  切记这样做会算入重复的点  想一下菱形的拓扑序的样子 最后一个点在最开始的点的眼中会被计算两次）
//
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<bitset>
using namespace std;

const int N = 3e4+10;

int d[N];
struct head{
    vector<int> e;
};
head g[N];
vector<int> seq;
bitset<N> f[N];
map<int,int> mp;
int n,m;
// 思路一：在对原图的逆拓图进行排序的时候直接进行一个可达边的累计（不可行  切记这样做会算入重复的点  想一下菱形的拓扑序的样子 最后一个点在最开始的点的眼中会被计算两次）
//void bfs(){
//    queue<int> q;
//    for(int i = 1;i<=n;++i){
//        if(!d[i]){
//            q.push(i);
//        }
//        reachable[i] = 1;//初始化所有点初始的可达点数量都是1 （都可以到自己）
//    }
//    while(!q.empty()){
//        int t = q.front();
//        q.pop();
//        for(auto x:g[t].e){ //遍历当前点的边 找到下一个节点
//            d[x]--;
//            reachable[x] += reachable[t]; // reachable 记录当前下标对应的点可达其他点的数量
//            if(!d[x]){
//                q.push(x);
//            }
//        }
//    }
//}


void bfs(){
    queue<int> q;
    for(int i = 1;i<=n;++i){
        if(!d[i])q.push(i);
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        seq.push_back(t);
        for(auto x:g[t].e){
            d[x]--;
            if(!d[x]) q.push(x);
        }
    }



}


int main(){
    cin>>n>>m;
//    memset(reachable,1,sizeof reachable);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        // 去重
//        if(mp[y]!=x){
//            mp[y] = x;
//            g[y].e.push_back(x);
//            d[x]++;
//        }
        g[x].e.push_back(y);
        d[y]++;

    }
    bfs();
    for(int i = n-1;i>=0;--i){
        int j = seq[i];
        f[j][j] = 1;
        for(auto x:g[j].e){
            f[j] |= f[x];
        }
    }

    for(int i = 1;i<=n;++i)cout<<f[i].count()<<endl;


    return 0;
}
