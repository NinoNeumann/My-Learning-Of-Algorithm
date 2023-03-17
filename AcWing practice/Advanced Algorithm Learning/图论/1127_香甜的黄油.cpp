//
// Created by Nino Neumann on 2023/3/6.
//
// 思路 最小生成树
// 奶牛数量是每个点的权值 在 kruskal计算最小生成树的总权重和的时候要乘上每个节点的权重
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 1500;

struct edge{
    int a,b,c;
    bool operator<(const edge& t) const {
        return c<t.c;
    }
}edges[N];

int p[N];
int num[N]; // 记录每个节点的奶牛数量
int n,m,c;

int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}



int main(){
    cin>>n>>m>>c;
    for(int i = 0;i<n;++i){
        int x;
        cin>>x;
        num[x]++;
    }
    for(int i = 0;i<c;++i){
        scanf("%d%d%d",&edges[i].a,&edges[i].b,&edges[i].c);
    }

    sort(edges,edges+m);
    for(int i = 0;i<=m;++i) p[i] = i;

    int res = 0;
    for(int i = 0;i<c;++i){
        int a = edges[i].a,b = edges[i].b,c = edges[i].c;
        int fa = find(a),fb = find(b);
        if(fa!=fb){
            p[fa] = fb;
            res+=c;
        }
    }
    cout<<res<<endl;


    return 0;
}

