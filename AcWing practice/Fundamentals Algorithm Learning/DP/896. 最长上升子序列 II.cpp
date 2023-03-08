//
// Created by Nino Neumann on 2023/3/8.
//
#include<iostream>
using namespace std;

const int N = 1e5+10;


int f[N],g[N];
int k[N];
int n;

int main(){

    cin>>n;
    for(int i = 1;i<=n;++i)scanf("%d",&g[i]);
    int mx = 0;
    int len = 0;
    for(int i = 1;i<=n;++i){
        // 找到那个g[i]>g[j] 中的 最大 的f[j]
        int l = 0,r = len;
        while(l<r){
            int mid = l+r+1>>1;
            if(q[mid]>g[i]) r = mid;
            else l = mid+1
        }
        q[l+1] = g[i];
        len = max(len,r+1);
    }

    cout<<len<<endl;
    return 0;
}