//
// Created by Nino Neumann on 2023/3/3.
//
// Flood Fill算法
//   难点：如何去判断不是peak 或者 valley的情况并且在这种非二分情况下找两个极致

//  思路：

#include<iostream>
#include<queue>
#include<algorithm>
#define x first
#define y second
using namespace std;
const int N = 1010;

typedef pair<int,int> PII;


int g[N][N];
bool st[N][N]; // 记录当前格子是否被加入了peak 或者valley的集合中
int n;


void dfs(int x,int y,bool& has_higher,bool& has_lower){

    queue<PII> q;
    q.push({x,y});
    st[x][y] = true;
    while(!q.empty()){
        auto t = q.front();
        q.pop();

        for(int x_next = t.x-1;x_next<=t.x+1;++x_next)
            for(int y_next = t.y-1;y_next<=t.y+1;++y_next){
                if(x_next<0 || x_next>=n || y_next<0 || y_next>=n) continue;
                if(g[x_next][y_next]!=g[t.x][t.y]){
                    if(g[x_next][y_next]<g[t.x][t.y]) has_lower = true;
                    else has_higher = true;
//                    return;
                }else if(!st[x_next][y_next]){
                    q.push({x_next,y_next});
                    st[x_next][y_next] = true;
                }
            }
    }

    return;
}



int main(){
    cin>>n;
    int peak = 0, valley = 0;

    for(int i = 0;i<n;++i)
        for(int j = 0;j<n;++j)
            scanf("%d",&g[i][j]);

    for(int i = 0;i<n;++i)
        for(int j = 0;j<n;++j){
            if(!st[i][j]){
                // 为什么不能设置 如果当前为highest 就 peak++
                bool has_higher = false,has_lower = false;
                dfs(i,j,has_higher,has_lower);
                if(!has_higher) peak++;
                if(!has_lower) valley++;
            }
        }

    cout<<peak<<" "<<valley;



    return 0;
}

