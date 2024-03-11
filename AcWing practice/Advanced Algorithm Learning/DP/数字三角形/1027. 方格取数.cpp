//
// Created by Nino Neumann on 2024/3/10.
//

// 要求，两条路上最大值之和
// 思路：计算两次 每次将取得最大值的点数置为0

#include "iostream"
#include "cstring"
using namespace std;
const int N = 11;

int g[N][N];
int f[N][N][N]; // 三个状态表示当前两条路的走法

int main(){
    int n;
    int x,y,c;
    int res = 0;
    while(cin>>x>>y>>c && ( x || y || c)){
        g[x][y] = c;
    }



    return 0;
}
