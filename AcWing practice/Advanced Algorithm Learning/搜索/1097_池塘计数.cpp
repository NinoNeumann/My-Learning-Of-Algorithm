//
// Created by Nino Neumann on 2023/3/2.
//
#include<iostream>
#include<queue>
#include<algorithm>

#define x first
#define y second
using namespace std;

typedef pair<int,int> PII;
const int N = 1010;
char g[N][N];

int dis_x[] = {-1,1, 0,0,-1, 1,-1,1};
int dis_y[] = { 0,0,-1,1,-1, -1,1,1};


int n,m;

int bfs(int xs,int ys){
    int res = 0;
    queue<PII> q;
    q.push({xs,ys});
    g[xs][ys] = '.';
    while(q.size()){
        auto t = q.front();
        q.pop();
        res++;
        for(int i = 0;i<8;++i){
            int x = t.x+dis_x[i],y = t.y+dis_y[i];
            if(x<0 || y<0 || x>=n || y>=m || g[x][y]!='W') continue;
            q.push({x,y});
            g[x][y] = '.';
        }
    }

    return res;

}


int main(){
    cin>>n>>m;
    int res = 0;
    for(int i = 0;i<n;++i)cin>>g[i];
    // 遍历所有的点分别以其为起始点flood fill
    for(int i = 0;i<n;++i)
        for(int j = 0;j<m;++j)
            if(g[i][j]=='W'){
                if(bfs(i,j))res++;
            }
    cout<<res<<endl;
    return 0;
}