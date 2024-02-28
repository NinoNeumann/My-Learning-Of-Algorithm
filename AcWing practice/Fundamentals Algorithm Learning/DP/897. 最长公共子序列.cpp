//
// Created by Nino Neumann on 2024/2/28.
//
#include<iostream>
using namespace std;
const int N = 1010;

int f[N][N]; // fij 的实际意义是以ai bj结尾的两个字符串最长的公共子串的长度
char a[N],b[N];
int n,m;

int main(){
    cin>>n>>m>>a+1>>b+1;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            // 两种情况：
            // 1、 末尾ai == bj 则当前的fij = 前一个 fi-1 j-1 + 1 长度加一
            // 2、不相等 fij = max fi-1j  fij-1
            if(a[i]==b[j]) f[i][j] = f[i-1][j-1]+1;
            else f[i][j] = max(f[i-1][j],f[i][j-1]);
        }
    }
    cout<<f[n][m];


    return 0;
}