//
// Created by Nino Neumann on 2023/3/3.
//
#include<iostream>
#include<queue>
#include<algorithm>

#define x first
#define y second

using namespace std;
const int N = 55;

typedef pair<int,int> PII;
// 需要一个二维数组表示房间的状态：当前房间有没有被flood fill过
bool st[N][N];
int g[N][N];
int n,m;
// 方向偏置
int dis_x[] = {0,-1,0,1};
int dis_y[] = {-1,0,1,0};

int bfs(int x,int y){ // 输出当前联通块的面积
    // 将当前的位置加入queue中
    if(st[x][y])return 0; // 当前已经被算过了
    int area = 1;
    queue<PII> q;
    st[x][y] = true;
    q.push({x,y});
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int s_t = g[t.x][t.y];//记录t点的墙壁数字
//        area++;
        // 遍历当前状态的可行进方向
        for(int i = 0;i<4;++i){ // 这里枚举的时候一定要注意枚举顺序和方向是有关的 并不是随机枚举
            if(s_t >>i & 1)continue;
            int x_next = t.x+dis_x[i],y_next = t.y+dis_y[i];
            if(x_next<0 || x_next>=n || y_next<0 || y_next>=m) continue;
            if(st[x_next][y_next]) continue;
            q.push({x_next,y_next});
            st[x_next][y_next] = true;
            area++; // 由出队节点数计算当前块的面积 或者由入队节点数计算当前块的面积（用入队算得在初始状态+1）都一样
        }
    }
    return area;
}


int main(){
    cin>>n>>m;
    for(int i = 0;i<n;++i)
        for(int j = 0;j<m;++j)
            cin>>g[i][j];
    int res = 1;
    int num = 0;
    for(int i = 0;i<n;++i)
        for(int j = 0;j<m;++j){
            int k = bfs(i,j);
            if(k){
                num++;
                res = max(k,res);
            }
        }
    cout<<num<<endl;
    cout<<res<<endl;
    return 0;
}