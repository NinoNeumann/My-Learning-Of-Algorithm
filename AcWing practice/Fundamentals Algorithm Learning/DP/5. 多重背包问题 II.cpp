//
// Created by Nino Neumann on 2023/3/7.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1010;

struct good{
    int v,w;
};

vector<good> goods;
int f[N];

int n,m;

int main(){
    cin>>n>>m;
//    goods.push_back({0,0});
    for(int i = 1;i<=n;++i){
        int v,w,s;
        cin>>v>>w>>s;
        int k = 1;
        // 给出的k序列需要能够满足拼成所有小于等于s的数
        while(k<=s){
            s -= k;
            goods.push_back({k*v,k*w});
            k <<= 1;
        }
        if(s){
            goods.push_back({s * v, s * w});
        }
    }

    for(auto x:goods){
        for(int j = m;j>=x.v;--j){
            f[j] = max(f[j],f[j-x.v]+x.w);
        }
    }

    // 二维版本
//    for(int i = 1;i<=goods.size()-1;++i){
//        for(int j = 1;j<=m;++j){
//            f[i][j] = f[i-1][j];
//            if(j>=goods[i].v) f[i][j] = max(f[i][j],f[i-1][j-goods[i].v]+goods[i].w);
//        }
//    }

    cout<<f[m];


}