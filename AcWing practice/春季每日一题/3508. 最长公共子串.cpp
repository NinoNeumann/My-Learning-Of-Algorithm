//
// Created by Nino Neumann on 2023/4/19.
//
// 求公共子串一定要和求解公共子序列分开


#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4+10;

int f[N];
char a[N],b[N];


int main(){
    scanf("%s%s",a+1,b+1);
    int a_len = strlen(a+1);
    int b_len = strlen(b+1);
    int mx = 0;
    for(int i = 1;i<=a_len;++i){
        for(int j = b_len;j>=1;--j){
            if(a[i]==b[j] && a[i]>='a') f[j] = f[j-1]+1;
            else f[j] = 0;
            mx = max(mx,f[j]);
        }
    }
    printf("%d\n",mx);
//    cout<<mx<<endl;

    return 0;
}