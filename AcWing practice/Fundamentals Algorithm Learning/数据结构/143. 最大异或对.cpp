//
// Created by Nino Neumann on 2024/3/1.
//
#include<iostream>
using namespace std;

const int N = 3e6+10;

int tree[N][2],idx,cnt[N];
int nums[N];

void insert(int s){
    int p = 0;
    for(int i = 30;~i;--i){
        int u = (s>>i)&1;
        // cout<<u;
        if(!tree[p][u]) tree[p][u] = ++ idx;
        p = tree[p][u];
    }
    // cout<<endl;
    cnt[p]++;
}

int query(int s){
    int p = 0;
    int res = 0;
    for(int i = 30; ~i; -- i){
        int u = (s>>i)&1;
        if(tree[p][!u]){
            res += (1<<i);
            p = tree[p][!u];
        }
        else p = tree[p][u];
    }
    // cout<<endl;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    int n,res = 0;
    cin>>n;
    for(int i = 0;i<n;++i){
        cin>>nums[i];
        insert(nums[i]);
    }

    for(int i = 0;i<n;++i){
        res = max(query(nums[i]),res);
    }
    cout<<res;


    return 0;
}