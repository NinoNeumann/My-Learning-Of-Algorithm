//
// Created by Nino Neumann on 2023/4/23.
//
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;

int w[N];
int tree[N];
int n,cnt;

void pre_order(int u){
    int r_tree = u<<1;
    int l_tree = (u<<1)+1;
    if(r_tree<=n)
        pre_order(r_tree);
    tree[u] = w[cnt++];
    if(l_tree<=n)
        pre_order(l_tree);
}


int main(){

    cin>>n;
    for(int i = 0;i<n;++i)cin>>w[i];
    sort(w,w+n);
    pre_order(1);
    cout<<tree[1];
    for(int i = 2;i<=n;++i) cout<<" "<<tree[i];


    return 0;
}