//
// Created by Nino Neumann on 2023/3/9.
//
// 完全背包问题
// 难点在于如和在dp过程中追踪到最优的方案
#include<iostream>
#include<vector>
#define volume first
#define worth second
using namespace std;

typedef pair<int,int> PII;
const int N = 20;

struct team{
    vector<PII> e;
};

team teams[N];
int methods[N];
int f[N][N];

int n,m;

int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=m;++j){
            int w;
            cin>>w;
            teams[i].e.push_back(j,w); // j是占用的体积 w是价值
        }
    for(int i = 1;i<=n;++i){
        int cnt = 0;
        for(int j = 0;j<teams[i].e.size();++j){
            int v = teams[i].e[j].volume,w = teams[i].e[j].worth;

            for(int k = m;k>=v;++k){
                if(f[j][k]<f[j-1][k-v]){
                    f[j][k] = max(f[j][k],f[j-1][k-v]);
                    cnt = k;
                }
            }
        }
        methods[i] = cnt;
    }
    cout<<f[n][m];

    return 0;
}
