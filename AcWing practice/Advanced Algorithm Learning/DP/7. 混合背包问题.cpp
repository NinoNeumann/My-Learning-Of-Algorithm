//
// Created by Nino Neumann on 2023/3/8.
//
#include<iostream>
#include<vector>
using namespace std;

const int N = 1010;
struct good{
    int v,w,s;
};

vector<good> goods;

int f[N];
int n,m;

int main(){
    cin>>n>>m;
    goods.push_back({0,0,0});
    for(int i = 0;i<n;++i){
        int v,w,s;
        cin>>v>>w>>s;
        if(s<=0) goods.push_back({v,w,s});
        else {
            int k = 1;
            while(k<=s){
                s -= k;
                goods.push_back({v*k,w*k,-1});
                k <<= 1;
            }
            if(s) goods.push_back({v*s,w*s,-1});
        }
        // TLE 了 将所有多重背包问题转换为01背包

    }
    n = goods.size()-1;
    for(int i = 1;i<=n;++i){
        auto g = goods[i];
        // 混合背包问题的分界点在第二层循环外第一层循环内而不是在第二层循环内
        // 问题在于其实完全背包和01背包 在第二层循环的顺序上就不同所以不能公用第二层循环
        if(g.s==-1){
            // 01背包
            for(int j = m;j>=g.v;--j)f[j] = max(f[j],f[j-g.v]+g.w);
        }else{
            for(int j = g.v;j<=m;++j)f[j] = max(f[j],f[j-g.v]+g.w);
        }
//        for(int j = 1;j<=m;++j){
//            f[i][j] = f[i-1][j];
//            if(g.s==-1){
//                f[i][j] = max(f[i][j],f[i-1][j-g.v]+g.w);
//            }else if(g.s==0){
//                f[i][j] = max(f[i][j],f[i][j-g.v]+g.w);
//            }else{
//                for(int k = 0;k<=g.s;++k)
//                    if(j>=k*g.v) f[i][j] = max(f[i][j],f[i-1][j-k*g.v]+k*g.w);
//            }
//        }
    }

    cout<<f[m];
    return 0;
}