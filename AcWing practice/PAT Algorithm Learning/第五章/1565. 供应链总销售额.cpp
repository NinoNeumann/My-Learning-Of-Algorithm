//
// Created by Nino Neumann on 2023/4/27.
//
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int N = 1e5+10;

vector<int> heads[N];

int n;
int scale[N];
double p,rate;
double res;


void dfs(int root,int d){
    if(heads[root].empty()){
        res += pow(rate,d)*p*scale[root];
        return;
    }
    for(auto x:heads[root]){
        dfs(x,d+1);
    }
}


int main(){
    scanf("%d%lf%lf",&n,&p,&rate);
    rate /= 100;
    rate += 1;
    for(int i = 0;i<n;++i){
        int k,t;
        scanf("%d",&k);
        if(!k){
            scanf("%d",&t);
            scale[i] = t;
        }else{
            for(int j = 0;j<k;++j){
                scanf("%d",&t);
                heads[i].push_back(t);
            }
        }
    }
    dfs(0,0);
    printf("%.1f",res);

    return 0;
}