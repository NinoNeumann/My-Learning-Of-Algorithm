//
// Created by Nino Neumann on 2023/3/4.
//
// 基础算法 gcd
#include<iostream>
#include<cstring>
using namespace std;

const int N = 12;

int num[N];
//int f[N];  // 前i个数字组成组数为j的集合
int n;

// 如果两个数的最大公约数为1那么两个数互质 a b 互质 b c 互质 ===> a c互质？

int gcd(int x,int y){
    if(y)return gcd(y,x%y);
    return x;
}

int main(){
    cin>>n;
    for(int i = 0;i<n;++i)cin>>num[i];


    return 0;
}