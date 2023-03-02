//
// Created by Nino Neumann on 2023/3/2.
// 四个方向可行进
// 本题中dfs如何保证 能判断a点无法到达b的状态
// dfs 快很多

#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;

int dis_x[] = {-1,1,0, 0};// 0:up 1:down
int dis_y[] = {0 ,0,1,-1};// 2:right 3: left

char g[N][N];
bool st[N][N];  // 记录当前所在位置的状态以便回溯用
int n;
int x_b,y_b;//终点

bool dfs(int x,int y){
    if(x==x_b && y==y_b) return true;
    if(g[x][y]=='#') return false;
    //  这里要预先设置当前状态为 true 也是为了当上一层调用的时候来判断可行与否
    // 其实当能调用这个函数的时候已经说明当前的x y 肯定可行 （初次调用的时候要预先加一个边界条件判断）
    st[x][y] = true;
    // cout<<"yes\n";
    for(int i = 0;i<4;++i){
        int x_next = x+dis_x[i];
        int y_next = y+dis_y[i];
        // 判断下一个位置有没有越界 并且可走
        if(x_next>=0 && x_next<n && y_next>=0 && y_next<n && !st[x_next][y_next]){
            // 这里不需要设置下一步的状态
//            st[x_next][y_next] = true;
            if(dfs(x_next,y_next)) return true;
            // else return false;
//            st[x_next][y_next] = false;
        }

    }
    return false;

}


int main(){
    int k;
    // cout<<"yes\n";
    cin>>k;
    while(k--){
        cin>>n;
        int x_a,y_a;
        for(int i = 0;i<n;++i)
            for(int j = 0;j<n;++j)
                cin>>g[i][j];
        scanf("%d%d%d%d",&x_a,&y_a,&x_b,&y_b);
        // cout<<x_a<<" "<<y_a<<" "<<x_b<<" "<<y_b<<endl;
        // 边界条件判断
        memset(st,0,sizeof st); // 一定要保证状态记录每次清零
        if(g[x_a][y_a] == '#' || g[x_b][y_b] == '#'){
            cout<<"NO"<<endl;
            continue;
        }
        if(dfs(x_a,y_a))cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}

