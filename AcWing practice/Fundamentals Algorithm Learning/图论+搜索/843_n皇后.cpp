//
// Created by Nino Neumann on 2023/3/2.
//
// 问题：如何把对角线上的棋子记录到对角线的数组中
#include<iostream>
using namespace std;


const int N = 20;

char board[N][N];
bool cols[N],dg[N],udg[N];
int n;


void print_board(){
    // 不够简洁
//    for(int i = 0;i<n;++i){
//        for(int j = 0;j<n;++j){
//            cout<<board[i][j];
//        }
//        cout<<endl;
//    }
//    cout<<endl;
    for(int i = 0;i<n;++i)puts(board[i]);
    puts("");
    return;
}
void dfs(int depth){
    // depth 其实代表了行 第几行。
    int x = depth;
    if(depth==n) {
        print_board(); // 搜索到底开始输出
        return;
    }

    for(int y = 0;y<n;++y){
        // 枚举第i个位置 并判断这个位置适不适合放置
        if(!cols[y] && !dg[y-x+n] && !udg[y+x]){
            board[x][y] = 'Q';
            cols[y] = true;
            dg[y-x+n] = true;
            udg[y+x] = true;
            dfs(x+1);
            cols[y] = false;
            dg[y-x+n] = false;
            udg[y+x] = false;
            board[x][y] = '.';
        }
    }
}

void init(){
    // 初始化board
    for(int i = 0;i<n;++i)
        for(int j = 0;j<n;++j)board[i][j] = '.';
}

int main(){

    cin>>n;
    init();
    dfs(0);


    return 0;
}