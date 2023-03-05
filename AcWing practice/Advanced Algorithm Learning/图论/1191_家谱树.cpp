//
// Created by Nino Neumann on 2023/3/5.
//
// 输出拓扑序列
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 110;

struct head{
    vector<int> e;
};

head g[N]; //图结构
int d[N];  //存储每个节点的入度
vector<int> res_seq; // 结果序列
int n;


void dfs(){
    queue<int> q;
    // 将所有入度为0 的节点入队
    for(int i = 1;i<=n;++i)
        if(!d[i])q.push(i);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        res_seq.push_back(t);
        for(auto x:g[t].e){
            d[x]--;
            if(!d[x])q.push(x);
        }
    }
}

int main(){
    cin>>n;
    for(int i = 1;i<=n;++i){
        int t;
        while(cin>>t,t){
            g[i].e.push_back(t);
            d[t]++;
        }

    }
    dfs();
    for(auto x:res_seq)cout<<x<<" ";

    return 0;
}
