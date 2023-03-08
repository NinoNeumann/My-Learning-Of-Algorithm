//
// Created by Nino Neumann on 2023/3/8.
//
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;


const int N = 6e4+10;

vector<int> g[N];
int happy[N];
int f[N][2];
bool has_father[N];

int n;



void dfs(int n){
    f[n][1] = happy[n];
    for(auto s:g[n]){
        dfs(s);
        f[u][0] += max(f[s][0],f[s][1]);
        f[u][1] += f[s][0];
    }
}



int main(){
    cin>>n;
//    memset(f,-1,sizeof f);
    for(int i = 1;i<=n;++i) cin>>happy[i];
    for(int i = 1;i<=n;++i){
        int a,b;
        cin>>a>>b;
        has_father[a] = true;
        g[b].push_back(a);
    }

    int root = 1;
    while(has_father[root]) root++;
    dfs(root);
    cout<<max(f[root][0],f[root][1]);



    return 0;
}