//
// Created by Nino Neumann on 2024/3/3.
//

// 给出四个正方体箱子的边长，问能装下这四个正方体箱子
// 的大正方体边长最小要多大，要求边长最小且必须能装下四个箱子。

// 最大的两个箱子的边长之和
#include "iostream"
#include "algorithm"
using namespace std;

int a[4];

int main(){
    for(int i = 0;i<4;++i) cin>>a[i];
    sort(a,a+4);
    cout<<a[3]+a[2];
}
