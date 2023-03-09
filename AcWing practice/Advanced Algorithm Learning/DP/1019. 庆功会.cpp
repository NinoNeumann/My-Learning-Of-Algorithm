//
// Created by Nino Neumann on 2023/3/8.
//
// 多重背包问题  使用二进制分解的机制
#include<iostream>
#include<vector>
using namespace std;


const int N = 600;
const int M = 6006;
//int v[N],w[N],s[N];
struct good{
    int v,w;
};
vector<good> goods;
int f[M];
int n,m;

int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        int v,w,s;
        cin>>v>>w>>s;
        int k = 1;
        while(k<=s){
            s -= k;
            goods.push_back({k*v,k*w});
            k >>= 1;
        }
        if(s)goods.push_back({s*v,s*w});
    }

    for(auto g:goods){
        for(int j = m;j>=g.v;--j){
            f[j] = max(f[j],f[j-g.v]+g.w);
        }
    }

    cout<<f[m]<<endl;
    return 0;
}
