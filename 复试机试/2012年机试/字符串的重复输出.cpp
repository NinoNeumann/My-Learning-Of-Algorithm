//
// Created by Nino Neumann on 2024/3/3.
//
// 水题
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5+10;
char a[N];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin>>a;
    cin>>n;
    for(int i = 0;a[i];++i)
        for(int k = 0;k<n;++k)
            cout<<a[i];
    cout<<endl;
    return 0;
}
