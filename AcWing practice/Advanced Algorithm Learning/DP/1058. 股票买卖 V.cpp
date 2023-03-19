//
// Created by Nino Neumann on 2023/3/19.
//
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5+10;
const int INF = 0x3f3f3f3f;

int f[N][3];
int w[N];
int n;

int main(){
    cin>>n;
    for(int i = 1;i<=n;++i) scanf("%d",&w[i]);

//    memset(f,-0x3f,sizeof f);
    f[0][1] = f[0][2] = -INF;
    f[0][0] = 0;

    for(int i = 0;i<=n;++i) f[i][0] = 0;
    for(int i = 1;i<=n;++i){
        f[i][0] = max(f[i-1][0],f[i-1][2]);
        f[i][1] = max(f[i-1][1],f[i-1][0]-w[i]);
        f[i][2] = f[i-1][1]+w[i];
    }

//    int res = 0;
    cout<<max(f[n][2],f[n][0])<<endl;


    return 0;
}
