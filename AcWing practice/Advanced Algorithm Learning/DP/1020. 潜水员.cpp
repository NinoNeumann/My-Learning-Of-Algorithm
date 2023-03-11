//
// Created by Nino Neumann on 2023/3/9.
//
//  二维费用的混合背包问题
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N = 100;

struct container{
    int o,n,w;
};

vector<container> containers;

int f[N][N];

int n,m,k;

int main(){
    cin>>n>>m; // 氧气和氮气的需求量
    cin>>k;
    while(k--){
        int o,n,w;
        cin>>o>>n>>w;
        containers.push_back({o,n,w});
    }
    memset(f,0x3f,sizeof f);
    f[0][0] = 0;
    for(auto c:containers){
        // 存在单一物品的“体积大于当下所需的” 所以要变一下
        for(int i = n;i>=0;--i){
            for(int j = m;j>=0;--j){
                f[i][j] = min(f[i][j],f[max(0,i-c.o)][max(0,j-c.n)]+c.w);
            }
        }
//        for(int i = n;i>=c.o;--i){
//            for(int j = m;j>=c.n;--j){
//                f[i][j] = min(f[i][j],f[i-c.n][j-c.n]+c.w);
//            }
//        }
    }
    cout<<f[n][m];
    return 0;
}
