//
// Created by Nino Neumann on 2024/3/1.
//
#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,int> book;

int main(){
    ios::sync_with_stdio(false);
    int n;
    int res = 0,res_idx = -1;
    cin>>n;
    for(int i = 0;i<n;++i){
        int t;
        cin>>t;
        book[t]++;
        if(res<book[t]){
            res = book[t];
            res_idx = t;
        }else if(res==book[t]){
            if(res_idx>t)
                res_idx = t;
        }
    }
    cout<<res_idx;



}