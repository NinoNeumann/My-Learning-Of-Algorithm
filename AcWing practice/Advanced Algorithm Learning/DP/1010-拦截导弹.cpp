//
// Created by Nino Neumann on 2023/3/1.
//
// Dilworth 定理 ：最长反链=最小覆盖链个数
#include<iostream>
using namespace std;
const int N = 1010;
int a[N],f[N],g[N];


int main(){
    int n = 1;
    int res1 = 0;
    int res2 = 0;
    while(cin >> a[n]) n++;
    n--; // 由于一开始的时候n偏移了一个单位 所以后面要减一
    // 求最长子链
    for(int i = n;i>=1;--i){
        f[i] = 1;
        for(int j = i+1;j<=n;++j)
            if(a[i]>=a[j]) f[i] = max(f[i],f[j]+1);
    }

    for(int i = 1;i<=n;++i){
        f[i] = 1;
        for(int j = i-1;j>=0;--j)
            if(a[i]>a[j]) g[i] = max(g[i],g[j]+1);
    }

    for(int i = 1;i<=n;++i)res1 = max(res1,f[i]),res2 = max(res2,g[i]);
    cout<<res1<<"\n"<<res2;





    return 0;
}
