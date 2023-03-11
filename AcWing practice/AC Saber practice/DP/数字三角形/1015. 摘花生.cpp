//
// Created by Nino Neumann on 2023/3/11.
//
// 试着倒序考虑
#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;

int g[N][N],f[N][N];


int main(){
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        for(int i = 1;i<=r;++i){
            for(int j = 1;j<=c;++j){
                cin>>g[i][j];
            }
        }

        for(int i = r;i>=1;--i){
            for(int j = c;j>=1;--j){
                f[i][j] = max(f[i+1][j],f[i][j+1])+g[i][j];
            }
        }

        cout<<f[1][1]<<endl;

        memset(g,0,sizeof g);
        memset(f,0,sizeof f);
    }
    return 0;
}
