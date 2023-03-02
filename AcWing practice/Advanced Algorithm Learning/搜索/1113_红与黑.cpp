//
// Created by Nino Neumann on 2023/3/2.
//

// flood fill 算法
// 针对网格图  求联通块：
// 思路 从一个点开始遍历
// 顺序：BFS  DFS 没有区别 （DFS可能会有爆栈的风险  但是DFS更加方便  但BFS可以求一个最短距离）
// BFS 的时间复杂度 ：每次入队只会入队未被选中的格子 故时间复杂度为O（n^2）
#include<iostream>
#include<queue>
#include<algorithm>

#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N = 25;

char g[N][N];
int n,m;
int x_s,y_s;

int dis_x[] = {-1,1,0, 0};// 0:up 1:down
int dis_y[] = {0 ,0,1,-1};// 2:right 3: left

int bfs(int x_i,int y_i){

    queue<PII> k;
    // 先将初始的点推入队列中
    k.push({x_i,y_i});
    g[x_i][y_i] = '#';
    while(!k.empty()){
        int x_t  = k.front().x;
        int y_t = k.front().y;
        k.pop();
        // 枚举四个方向
        for(int i = 0;i<4;++i){
            int x_next = x_t + dis_x[i];
            int y_next = y_t + dis_y[i];
            // 越界检查
            if(x_next<0 || x_next>=n || y_next<0 || y_next>=m)continue;
            if(g[x_next][y_next]=='#') continue;
            k.push({x_next,y_next});
        }
    }
    return k.size();
}

int main(){
    while(cin>>n>>m, m || n){
        for(int i = 0;i<n;++i)cin>>g[i];
        for(int i = 0;i<n;++i)
            for(int j = 0;j<m;++j)
                if(g[i][j]=='@'){
                    x_s = i;
                    y_s = j;
                }

        cout<<bfs(x_s,y_s)<<endl;
    }


    return 0;
}




// 失败的算法 暂时没找到bug  方法就是暴力枚举

//#include<iostream>
//#include<cstring>
//#include<vector>
//using namespace std;
//typedef pair<int,int> PII;
//
//const int N = 22;
//char g[N][N];
//bool st[N][N];
//vector<PII> black;
//int n,m;
//int x_s,y_s;
//int dis_x[] = {-1,1,0, 0};// 0:up 1:down
//int dis_y[] = {0 ,0,1,-1};// 2:right 3: left
//
//
//bool dfs(int x,int y,int x_d,int y_d){
//    if(x==x_d && y==y_d) return true;
//    if(g[x][y]=='#') return false;
//    //  这里要预先设置当前状态为 true 也是为了当上一层调用的时候来判断可行与否
//    // 其实当能调用这个函数的时候已经说明当前的x y 肯定可行 （初次调用的时候要预先加一个边界条件判断）
//    st[x][y] = true;
//    // cout<<"yes\n";
//    for(int i = 0;i<4;++i){
//        int x_next = x+dis_x[i];
//        int y_next = y+dis_y[i];
//        // 判断下一个位置有没有越界 并且可走
//        if(x_next>=0 && x_next<n && y_next>=0 && y_next<n && !st[x_next][y_next]){
//            // 这里不需要设置下一步的状态
////            st[x_next][y_next] = true;
//            if(dfs(x_next,y_next,x_d,y_d)) return true;
//            // else return false;
////            st[x_next][y_next] = false;
//        }
//
//    }
//    return false;
//
//}
//
//
//int main(){
//    while(cin>>n>>m,n!=0 || m!=0){
//        memset(st,0,sizeof st);
//        int res = 0;
//        for(int i = 0;i<n;++i)
//            for(int j = 0;j<m;++j){
//                cin>>g[i][j];
//                if(g[i][j]=='@'){
//                    x_s = i;
//                    y_s = j;
////                    black.push_back({x_s,y_s});
//                }
//                if(g[i][j]=='.')black.push_back({i,j});
//            }
//        for(auto b:black){
//            if(dfs(x_s,y_s,b.first,b.second))res++;
//        }
//        cout<<res<<endl;
//    }
//
//    return 0;
//}
