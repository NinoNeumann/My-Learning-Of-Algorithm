//
// Created by Nino Neumann on 2023/3/1.
//
// 高精度运算详情参考前面的算法
// 本题的关键在于如何改写mod运算使之可以用在大数上
// yxc：使用快速幂  位运算  用加法实现乘法  龟速加
// 如何将b这个大数转换为一个二进制的01串？ 1、b没有超过long long 的表示范围 所以直接有意运算就ok
#include<iostream>
using namespace std;
typedef long long LL;




int main(){
    LL a,b,p,c = 0;
    cin>>a>>b>>p;
    // 龟速乘法
    while(b){
        if(b&1) c += a % p;
        a *= 2;
        b >>= 1;
    }
    cout<<c;


    return 0;
}






