//
// Created by Nino Neumann on 2023/3/16.
//
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N = 2e5+10;
const int INF = 0x3f3f3f3f;

int p[N];
struct node{
    int a,b,w;
    bool operator<(const node& t)const{
        return w<t.w;
    }
} edges[N];

int n,m;


int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}


int kruskal(){
    int res = 0,cnt = 0; // res记录最小生成树中所有的边值之和，cnt记录生成树中由多少个点
    // 遍历所有的边
    for(int i = 0;i<m;++i){
        int a = edges[i].a,b = edges[i].b,w = edges[i].w;
        int fa = find(a),fb = find(b);
        // 如果两个点不在一个联通分量中就先将其合并然后将 res 和 cnt 更新
        if(fa!=fb){
            p[fa] = fb;
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1)return INF;
    return res;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;++i){
        scanf("%d%d%d",&edges[i].a,&edges[i].b,&edges[i].w);
    }
    sort(edges,edges+m);
    // 初始化并查集
    for(int i = 0;i<=n;++i)p[i] = i;
    int res = kruskal();
    if(res!=INF)cout<<res<<endl;
    else
        cout<<"impossible\n";
    return 0;
}



