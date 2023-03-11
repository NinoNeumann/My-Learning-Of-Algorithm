//
// Created by Nino Neumann on 2023/3/11.
//
// 01背包问题
#include<iostream>
#include<vector>
using namespace std;
const int N = 3e4+10;

struct good{
    int v,w;
};

vector<good> goods;

int f[N];

int n,m;

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;++i){
        int t1,t2;
        cin>>t1>>t2;
        goods.push_back({t1,t1*t2});
    }
    for(auto g:goods){
        for(int j = n;j>=g.v;--j){
            f[j] = max(f[j],f[j-g.v]+g.w);
        }
    }
    cout<<f[n]<<endl;
    return 0;
}