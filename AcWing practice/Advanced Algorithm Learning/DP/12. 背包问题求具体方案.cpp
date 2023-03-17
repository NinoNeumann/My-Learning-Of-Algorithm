//
// Created by Nino Neumann on 2023/3/14.
//
// dp球具体方案==球最短路问题
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 1010;
int f[N];
bool st[N];
int n,m;


int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;++i){
        int v,w;
        cin>>v>>w;
        for(int j = m;j>=v;--j){
            int maxv = max(f[j],f[j-v]+w);
            if(maxv==f[j]) methods[j]
        }
    }

    return 0;
}
