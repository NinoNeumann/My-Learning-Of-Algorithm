//
// Created by Nino Neumann on 2023/3/4.
//
#include<iostream>
#include<cstring>
using namespace std;
const int N = 10;
bool st[N][N];
int dis_x[]={-2,-2,-1,-1,1,1,2,2};
int dis_y[]={-1,1,-2,2,-2,2,-1,1};

int n,m;
int res;

void dfs(int x,int y,int steps){
    if(steps==n*m)res++;
    st[x][y] = true;
    for(int i = 0;i<8;++i){
        int x_next = x+dis_x[i],y_next = y+dis_y[i];
        // 边界判断
        if(x_next<0 || y_next<0 || x_next>=n || y_next>=m) continue;
        if(st[x_next][y_next]) continue;

        dfs(x_next,y_next,steps+1);
        st[x_next][y_next] = false;
    }
    return ;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x_s,y_s;
        memset(st,false,sizeof st);
        res = 0;
        cin>>n>>m>>x_s>>y_s;
        dfs(x_s,y_s,1);
        cout<<res<<endl;
    }

    return 0;
}
