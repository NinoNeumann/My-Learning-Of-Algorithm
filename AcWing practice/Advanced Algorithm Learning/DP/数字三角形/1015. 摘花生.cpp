//
// Created by Nino Neumann on 2024/2/28.
//
#include<iostream>
#include<cstring>
using namespace std;

const int N = 101;

int T;

int G[N][N];
int f[N][N];



int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        // memset(f,0,sizeof f);
        int R,C;
        cin>>R>>C;
        for(int i = 1;i<=R;++i)
            for(int j = 1;j<=C;++j){
                int t;
                cin>>t;
                f[i][j] = max(f[i-1][j],f[i][j-1])+t;
            }
        cout<<f[R][C]<<endl;
    }

    return 0;
}