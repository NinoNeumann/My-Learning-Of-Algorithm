//
// Created by Nino Neumann on 2023/3/14.
//
// 输出最优解的方案数。
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1010;
const int mod = 1e9+7;

int g[N],f[N];

int n,m;
int main(){
    cin>>n>>m;
    memset(f,-0x3f,sizeof f);
    f[0] = 0;
    g[0] = 1;
    for(int i = 1;i<=n;++i){
        int v,w;
        cin>>v>>w;
        for(int j = m;j>=v;--j){
            int maxv = max(f[j],f[j-v]+w);
            int s = 0;
            if(maxv==f[j]) s = g[j];
            if(maxv==f[j-v]+w) s = (s + g[j-v]) % mod;
            f[j] = maxv;
            g[j] = s;
        }
    }

    int res = 0;
    for(int i = 0;i<=m;++i) res = max(res,f[i]);
    int s = 0;
    for(int i = 0;i<=m;++i){
        if(f[i]==res){
            s = (s + g[i]) % mod;
        }
    }
    cout<<s<<endl;
    return 0;
}




