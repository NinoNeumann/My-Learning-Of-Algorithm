//
// Created by Nino Neumann on 2024/3/1.
// https://noobdream.com/DreamJudge/Issue/page/1875/
#include<iostream>
using namespace std;
const int N = 1002;
int f[N][N];
char a[N],b[N];
int main(){
    cin>>a+1>>b+1;
    int j,i,mx = 0;
    for(i = 1;a[i];++i)
        for(j = 1;b[j];++j){
            if(a[i]==b[j]) f[i][j] = f[i-1][j-1]+1;
            mx = max(mx,f[i][j]);
        }
    cout<<mx;
    return 0;
}