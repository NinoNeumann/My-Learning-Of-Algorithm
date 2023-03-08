//
// Created by Nino Neumann on 2023/3/8.
//
// 前缀和？
#include<iostream>
using namespace std;
const int N = 1e5+10;
int num[N],f[N]; // f i 是1到i+1 的距离  特别的 f n 是1到自己闭环的距离 另一个方向就是总长度-当前这个长度
int n,q;
int main(){
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>num[i];
        //构造 前向前缀和
        f[i] = f[i-1]+num[i];  // 特别的 f n
    }
    cin>>q;
    int s,e;
    while(cin>>s>>e,q--){
        if(s>e) swap(s,e);
        cout<<min(f[e-1]-f[s-1],f[n]-f[e-1]+f[s-1])<<endl;
    }
    return 0;


}