//
// Created by Nino Neumann on 2023/3/6.
//
// 完全背包问题
// 状态定义
#include <iostream>
using namespace std;

const int N = 1010;

int w[] = {-1,10,20,50,100};
int n;
int f[5][N];

int main(){

    cin>>n;
    // 初始化
    f[0][0] = 1; // 参照数字组合那一题
    for(int i = 1;i<=4;++i){
        for(int j = 0;j<=n;++j){
            // 这里的递推方法和完全背包问题的公式递推是一样的
            f[i][j] = f[i-1][j];
            if(j>=w[i]) f[i][j] += f[i][j-w[i]];
        }
    }
    cout<<f[4][n];
    return 0;
}
