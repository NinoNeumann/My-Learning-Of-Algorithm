//
// Created by Nino Neumann on 2023/4/15.
//
#include<iostream>
#include<cstring>
using namespace std;

// 动态规划
// d(j) 前j个数组中组成 合法串的集合  值：最长  最长上升子序列！！！
// 运算 f [n] f[n-1]

const int N = 1e5+10;

int h[N],l[N],G[11];
int f[N];

int n;

int main(){
    scanf("%d",&n);
    int mx = 0;
    for(int i = 1;i<=n;++i){
        char s[11];
        scanf("%s",s);
        h[i] = s[0]-'0';
        l[i] = s[strlen(s)-1]-'0';
        f[i] = 1;
        f[i] = max(f[i],G[h[i]]+1);
        G[l[i]] = max(f[i],G[l[i]]);
        mx = max(f[i],mx);
    }
    cout<<n-mx<<endl;
    return 0;
}