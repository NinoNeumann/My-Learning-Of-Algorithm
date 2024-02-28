//
// Created by Nino Neumann on 2024/2/28.
//
#include<iostream>
using namespace std;

const int N = 1010;

int f[N][N]; // fij的实际意义：将i结尾的a串修改到j结尾的b串所需要的步骤
char a[N],b[N];
int n,m;

int main(){
    cin>>n>>a+1>>m>>b+1;
    // 需要初始化
    for(int i = 1; i <= n; ++ i) f[i][0] = i;
    for(int i = 1; i <= m; ++ i) f[0][i] = i;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            f[i][j] = min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+((a[i]==b[j])?0:1));

    cout<<f[n][m];

    return 0;
}
