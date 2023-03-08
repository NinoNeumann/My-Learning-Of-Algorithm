//
// Created by Nino Neumann on 2023/3/8.
//
#include<iostream>
using namespace std;

const int N = 1010;
int f[N];  // fi 表示以i结尾的 公共上升子序列的集合  属性 子序列的长度最大值
            // 状态计算：fi = sigma（fk+1）
int g[N];
int n;



int main(){
    cin>>n;

    int mx = 0;
    for(int i = 1;i<=n;++i)cin>>g[i];
    f[0] = 1;
    for(int i = 1;i<=n;++i){
        f[i] = 1;
        for(int j = 0;j<=i-1;++j)
            if(g[i]>g[j]) f[i] = max(f[i],f[j]+1);
        mx = max(mx,f[i]);
    }
    cout<<mx<<endl;

    return 0;
}