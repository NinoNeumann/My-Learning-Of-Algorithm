//
// Created by Nino Neumann on 2023/3/1.
//
// 经典矩阵前缀和 子矩阵前缀和
#include<iostream>
using namespace std;

int f[N][N],d[N][N];
int n;// 记录矩阵的大小

int init_d_matrix(){
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            d[i][j] += d[i-1][j-1]-d[i][j-1]-d[i-1][j];
        }
    }
}

int ssm(int x1,int y1,int x2,int y2){
    // 第x1 y1是左上角的坐标
    return d[x1-1][y1-1]+d[x2][y2]-d[x1-1][y2]-d[x2][y1-1];
}

const int N = 999;

int main(){


    return 0;
}
