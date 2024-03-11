//
// Created by Nino Neumann on 2024/3/8.
//
#include<iostream>
using namespace std;

int main(){
    int n;
    long long res = 1;
    int b;
    cin>>n;
    b = 2*n; // 计算卡特兰数
    for(int i = 1;i <= n;++i) res *= (b--),res /= i;
    cout<<res/(n+1);
    return 0;
}