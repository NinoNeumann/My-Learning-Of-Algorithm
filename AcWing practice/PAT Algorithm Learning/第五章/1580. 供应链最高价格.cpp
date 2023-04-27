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
double max_price;
int max_scale;


void dfs(int root,int d){
    double current_price = pow(rate,d)*p;
    if(heads[root].empty()){
        if(max_price<current_price){
            max_price = current_price;
            max_scale = 1;
        }else if(max_price==current_price){
            max_scale++;
        }
        return;
    }
    for(auto x:heads[root]){
        dfs(x,d+1);
    }
}


int main(){
    int root = 0;
    scanf("%d%lf%lf",&n,&p,&rate);
    rate /= 100;
    rate += 1;
    for(int i = 0;i<n;++i){
        int k,t;
        scanf("%d",&k);
        if(k!=-1)
            heads[k].push_back(i);
        else root = i;
    }
    dfs(root,0);
    printf("%.2f %d",max_price,max_scale);

    return 0;
}