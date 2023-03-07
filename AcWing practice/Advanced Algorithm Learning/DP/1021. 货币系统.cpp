//
// Created by Nino Neumann on 2023/3/6.
//
// 经典方案数问题 注意初始化 f00 = 1
// 十年oi一场空 不开longlong 见祖宗
#include<iostream>
using namespace std;
typedef long long LL;


const int M = 3300;
const int N = 16;

LL f[N][M];
int w[N];
int n,m;


int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        cin>>w[i];
    }

    //初始化
    f[0][0] = 1;
    for(int i = 1;i<=n;++i){
        for(int j = 0;j<=m;++j){
            f[i][j] = f[i-1][j];
            if(j>=w[i]) f[i][j] += f[i][j-w[i]];
        }
    }
    cout<<f[n][m];
    return 0;
}

