//
// Created by Nino Neumann on 2023/3/1.
//

#include<iostream>
using namespace std;
const int N = 1e5+10;
int f[N];

int get_bits(int x){
    // 返回x二进制中1的个数
    int res = 0;
    while(x){
        if(x&1)res++;
        x >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        int t;
        cin>> t;
        f[i] = get_bits(t);
    }
    for(int i = 0;i<n;++i)cout<<f[i]<<" ";


    return 0;
}
