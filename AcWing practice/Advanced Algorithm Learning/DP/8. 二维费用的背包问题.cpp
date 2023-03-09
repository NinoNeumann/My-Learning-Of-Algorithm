//
// Created by Nino Neumann on 2023/3/8.
//
// 二维01背包问题
#include<iostream>
#include<vector>
using namespace std;


const int N = 1010;
const int M = 101;

struct good{
    int v,z,w; // 体积 重量 价值
};
vector<good> goods;
int f[M][M];
int n,v,m;

int main(){
    cin>>n>>v>>m;
    for(int i = 0;i<n;++i){
        int x,y,z;
        cin>>x>>y>>z;
        goods.push_back({x,y,z});
    }
    for(auto g:goods){
        for(int j = v;j>=g.v;--j){
            for(int k = m;k>=g.z;--k){
                f[j][k] = max(f[j][k],f[j-g.v][k-g.z]+g.w);
            }
        }
    }
    cout<<f[v][m]<<endl;
    return 0;
}