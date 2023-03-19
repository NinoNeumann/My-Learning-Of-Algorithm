//
// Created by Nino Neumann on 2023/3/17.
//
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int,int> PII;

const int N = 100010;
const int M = 2*N;

int color_state[N];
//enum colors{red = 1,black = 2,no_color = 0};

struct head{
    vector<int> edges;
}heads[N];
int n,m;


bool dfs(int x,int color){
    color_state[x] = color;
    for(auto e:heads[x].edges){
        if(!color_state[e]){
            if(!dfs(e,3-color))return false;
        }
        if(color==color_state[e])return false;
    }
    return true;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        heads[u].edges.push_back(v);
        heads[v].edges.push_back(u);
    }

    bool flag = true;
    // 为什么初始要循环n次 应为二分图不一定都是联通的
    for(int i = 1;i<=n;++i){
        if(!color_state[i]){
            if(!dfs(i,1)){
                flag = false;
                break;
            }
        }

    }
    if(flag) puts("yes");
    else puts("no");

    return 0;
}

