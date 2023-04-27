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
double p,rate;
double min_price;
int min_scale;


void dfs(int root,int d){
    double current_price = pow(rate,d)*p;
    if(heads[root].empty()){
        if(min_price>current_price){
            min_price = current_price;
            min_scale = 1;
        }else if(min_price==current_price){
            min_scale++;
        }
        return;
    }
    for(auto x:heads[root]){
        dfs(x,d+1);
    }
}


int main(){
    int root = 0;
    min_price = 1e10+1;
    scanf("%d%lf%lf",&n,&p,&rate);
    rate /= 100;
    rate += 1;
    for(int i = 0;i<n;++i){
        int k,t;
        scanf("%d",&k);
        if(k){
            for(int j = 0;j<k;++j){
                scanf("%d",&t);
                heads[i].push_back(t);
            }
        }
    }
    dfs(root,0);
    printf("%.4f %d",min_price,min_scale);

    return 0;
}