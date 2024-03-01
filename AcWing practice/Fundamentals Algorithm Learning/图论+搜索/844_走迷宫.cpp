//
// Created by Nino Neumann on 2023/3/2.
//

// BFS中重要的几个要素
// 1 queue中应该装入什么状态
// 2 走迷宫中的 每一个状态对应的步数该如何表示 索引 存储
// 用的不顺的函数 string.find(char) 返回find的char在string中的位置
//             unordered_map.find() 查找成功和不成功返回什么
#include<iostream>
#include<queue>
using namespace std;

#define x first
#define y second

const int N = 101;

typedef pair<int,int> PII;


int G[N][N];
bool st[N][N];
int len[N][N]; // 使用额外的空间记录到达此点时候的路径最短。
int d_x[4] = {0, 1, 0, -1};
int d_y[4] = {1, 0, -1, 0};
int n,m;


void bfs(){
    queue<PII> q;
    q.push({1,1});
    st[1][1] = true;
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        if(f.x==n && f.y==m)
            return;
        for(int i = 0;i<4;++i){
            int x = f.x + d_x[i];
            int y = f.y + d_y[i];
            if(x >n || y > m || x<1 || y<1 || st[x][y] || G[x][y]) continue;
            st[x][y] = true;
            q.push({x,y});
            len[x][y] = len[f.x][f.y]+1;
        }
    }
}


int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j)
            cin>>G[i][j];

    bfs();
    cout<<len[n][m];


    return 0;
}