//
// Created by Nino Neumann on 2023/3/19.
//
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5+10;
const int K = 110;

int f[N][K][2];
int w[N];

int n,k;


int main(){
    cin>>n>>k;

    for(int i = 1;i<=k;++i) scanf("%d",&w[i]);
    // 初始化
    memset(f,-0x3f,sizeof f);
    for(int i = 1;i<=n;++i) f[i][0][0] = 0;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=k;++j){
            f[i][j][0] = max(f[i-1][j][0],f[i-1][j][1]+w[i]);
            f[i][j][1] = max(f[i-1][j][1],f[i-1][j-1][0]-w[i]);
        }
    }
    int res = 0;
    for(int i = 1;i<=n;++i) res = max(res,f[i][k][0]);
    cout<<res<<endl;


    return 0;
}
