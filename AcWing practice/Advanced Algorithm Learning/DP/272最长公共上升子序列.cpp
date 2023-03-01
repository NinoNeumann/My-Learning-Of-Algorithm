//
// Created by Nino Neumann on 2023/3/1.
//
#include<iostream>
using namespace std;
const int N = 3010;
int a[N],b[N];
int f[N][N];
// 最长公共子序列+ 单调  如何将这两个条件融合
// 状态表示- 集合：所有由第一序列 前i个字母 和 第二序列前j序列 由b【j】 或者a【i】结尾的上升子序列
// 状态计算：f
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)cin>>a[i];
    for(int i = 1;i<=n;++i)cin>>b[i];
    // 最长公共子序列
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            f[i][j] = max(f[i][j],f[i-1][j]);
            for(int k = j-1;k>=0;--k) f[i][j] = max(f[i][j],f[i][k]+1);
        }
    // 最长上升子序列
    for(int i = 1;i<=n;++i){
        f[i] = 1;
        for(int j = i-1;j>=0;--j){
            if(a[i]>a[j]) f[i] = max(...);
        }
    }


    }

    return 0;
}
